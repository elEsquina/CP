#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {  
    public:
    int n;
    vector<pair<int, int>> skylineHeight;
    SegmentTree(int size) {
        n = 1;
        while (n < size)
            n *= 2; 
        skylineHeight = vector<pair<int, int>>(2*n, {0,0});
    }

    int sum(int i, int l, int r, int h, int treeL, int treeR) {
        // no overlap
        if (l >= treeR || r <= treeL)
            return 0;
        // min value of building i's skyline
        if (skylineHeight[i].first > h)
            return 0;
        // max value of building i's skyline
        if (skylineHeight[i].second <= h)
            return min(r, treeR) - max(l, treeL);

        return sum(2*i, l, r, h, treeL, (treeL + treeR)/2) + sum(2*i + 1, l, r, h, (treeL + treeR)/2, treeR);
    }

    void update(int i, int l, int r, int h, int treeL, int treeR) {
        // no overlap
        if (l >= treeR || r <= treeL)
            return;
            
        // update max height of building i's skyline
        skylineHeight[i].second = max(skylineHeight[i].second, h);

        // update min height of building i's skyline
        if (l <= treeL && r >= treeR)
            skylineHeight[i].first = max(skylineHeight[i].first, h);
        else {
            update(2*i, l, r, h, treeL, (treeL + treeR)/2);
            update(2*i + 1, l, r, h, (treeL + treeR)/ 2, treeR);
            skylineHeight[i].first = max(skylineHeight[i].first, min(skylineHeight[2*i].first, skylineHeight[2*i + 1].first));
        }
    }

};

int main() {
    int c, n, l, r, h, overlap;

    cin >> c;
    while (c--) {
        cin >> n;
        overlap = 0;
        SegmentTree tree(100001);
        while (n--) {
            cin >> l >> r >> h;
            overlap += tree.sum(1, l, r, h, 0, tree.n);
            tree.update(1, l, r, h, 0, tree.n);
        }

        cout << overlap << endl;
    }
    return EXIT_SUCCESS;
}