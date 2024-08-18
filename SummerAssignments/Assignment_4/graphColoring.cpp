#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printVect(vector<int> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it;
        if (it != v.end() - 1) {
            cout << " ";
        } else
            cout << endl;
    }
}

class Graph {
   public:
    int size;
    vector<vector<int>> adj;

    Graph(int n) {
        size = n + 1;
        adj = vector<vector<int>>(size, vector<int>(0));
    }

    void addEdge(int start, int end) {
        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    void Backtracking(int u, vector<int> tmp, vector<int>& result, vector<int>& color) {
        vector<int> save;
        color[u] = -1;
        tmp.push_back(u);
        for (auto elem : adj[u]) {
            if (color[elem] == 0) {
                color[elem] = 1;
                save.push_back(elem);
            }
        }
        bool found = false;
        for (int v = u + 1; v < size; v++)
            if (color[v] == 0) {
                Backtracking(v, tmp, result, color);
                found = true;
                break;
            }
            
        if (!found && result.size() < tmp.size())
            result = tmp;
        for (auto saved: save)
            color[saved] = 0;
        color[u] = 1;
        tmp.pop_back();
        for (int v = u + 1; v < size; v++)
            if (color[v] == 0) {
                Backtracking(v, tmp, result, color);
                break;
            }
        color[u] = 0;
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
        vector<int> result;
        vector<int> color(g.size);
        g.Backtracking(1, result, result, color);

        cout << result.size() << endl;
        printVect(result);
    }

    return EXIT_SUCCESS;
}
