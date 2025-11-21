#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ---------- Kruskal ----------

struct Edge {
    int u, v, w;
};

bool cmpEdge(Edge a, Edge b) {
    return a.w < b.w;
}

int findParent(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rnk) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
}

void kruskalMST(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmpEdge);
    vector<int> parent(n), rnk(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstWeight = 0;
    cout << "Kruskal MST edges:\n";
    for (auto &e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if (pu != pv) {
            cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
            mstWeight += e.w;
            unionSet(pu, pv, parent, rnk);
        }
    }
    cout << "Total weight (Kruskal): " << mstWeight << endl;
}

// ---------- Prim ----------

void primMST(int n, vector<vector<int>> &graph) {
    vector<int> key(n, INT_MAX);
    vector<bool> inMST(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;
    cout << "\nPrim MST edges:\n";
    for (int v = 1; v < n; v++) {
        cout << parent[v] << " - " << v << " (w=" << graph[v][parent[v]] << ")\n";
        total += graph[v][parent[v]];
    }
    cout << "Total weight (Prim): " << total << endl;
}

int main() {
    int n = 5;

    // For Kruskal: edge list (undirected)
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(n, edges);

    // For Prim: adjacency matrix (0 = no edge)
    vector<vector<int>> graph(n, vector<int>(n, 0));
    graph[0][1] = graph[1][0] = 2;
    graph[0][3] = graph[3][0] = 6;
    graph[1][2] = graph[2][1] = 3;
    graph[1][3] = graph[3][1] = 8;
    graph[1][4] = graph[4][1] = 5;
    graph[2][4] = graph[4][2] = 7;
    graph[3][4] = graph[4][3] = 9;

    primMST(n, graph);

    return 0;
}
