#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int v, w;
};

void dijkstra(int src, vector<vector<Node>> &adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // min-heap: (distance, vertex)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int u = p.second;

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.v;
            int w = edge.w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << " : ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int n = 5;
    vector<vector<Node>> adj(n);

    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if undirected
    };

    addEdge(0, 1, 2);
    addEdge(0, 2, 4);
    addEdge(1, 2, 1);
    addEdge(1, 3, 7);
    addEdge(2, 4, 3);
    addEdge(3, 4, 1);

    dijkstra(0, adj);

    return 0;
}
