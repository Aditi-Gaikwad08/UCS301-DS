#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfsUtil(v, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsUtil(start, adj, visited);
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // same sample graph as BFS
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2, 5};
    adj[4] = {2};
    adj[5] = {3};

    cout << "DFS starting from node 0: ";
    dfs(0, adj);
    cout << endl;

    return 0;
}
