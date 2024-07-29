#include <iostream>
#include <vector>

using namespace std;

void printVect(vector<int> v) {
    for (auto elem:v)
        cout << elem << " ";
    cout << endl;
}

class Graph {
   public:
    int size;
    vector<vector<int>> adj;
    Graph(int n) {
        size = n;
        adj = vector<vector<int>>(size + 1, vector<int>(0));
    }

    void addEdge(int start, int end) {
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    bool noColoredNeighbours(int n, int color, vector<int> colors) {
        for (auto neighbour : adj[n]) {
            if (colors[neighbour] == color) 
                return false;
        }
        return true;
    }

    bool colorGraph(int n, vector<int> &optimalColor) {
        if (n == size + 1) 
            return true;
    
        for (int c = 0; c < 2; c++) {
            if (noColoredNeighbours(n, c, optimalColor)) {
                optimalColor[n] = c;
                if (colorGraph(n + 1, optimalColor))
                    return true;
                optimalColor[n] = -1;
            }
        }

        return false;
    }
};

int main() {
    int m, n, k, e1, e2;

    cin >> m;

    while (m--) {
        cin >> n >> k;
        Graph g = Graph(n);
        while (k--) {
            cin >> e1 >> e2;
            g.addEdge(e1, e2);
        }
        vector<int> colors(n + 1, -1);
        vector<int> optimal;
        g.colorGraph(1, colors);

        for (int i = 1; i <= n; i++) {
            if (colors[i] == 1)
                optimal.push_back(i);
        }
        cout << optimal.size() << endl;
        for (auto elem : optimal) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}
