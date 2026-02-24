#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if (n == 1) {
        cout << "0\n\n";
        return;
    }

    queue<int> q;
    vector<int> dist(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
            dist[i] = 0;
        }
    }
    int max_d = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (degree[i] > 1) {
            max_d = max(max_d, dist[i]);
        }
    }
    vector<int> miku_points;
    if (max_d != -1) {
        for (int i = 1; i <= n; ++i) {
            if (degree[i] > 1 && dist[i] == max_d) {
                miku_points.push_back(i);
            }
        }
    }
    cout << miku_points.size() << "\n";
    for (int i = 0; i < miku_points.size(); ++i) {
        cout << miku_points[i] << (i == miku_points.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
