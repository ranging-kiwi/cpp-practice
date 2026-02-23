#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500005;
const int INF = 1e9;
int ls[MAXN], rs[MAXN];
long long val[MAXN];
int f[MAXN];
int n, m_count;

void dfs(int u, long long X) {
    if (ls[u] == 0 && rs[u] == 0) {
        f[u] = (val[u] >= X ? 0 : INF);
        return;
    }
    dfs(ls[u], X);
    dfs(rs[u], X);

    long long cost_min = (long long)f[ls[u]] + f[rs[u]];
    long long cost_max = (long long)min(f[ls[u]], f[rs[u]]) + 1;
    
    f[u] = (int)min((long long)INF, min(cost_min, cost_max));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n)) return 0;

    m_count = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ls[i] >> rs[i];
        if (ls[i] != 0) m_count++; 
    }

    vector<long long> candidates;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        if (ls[i] == 0 && rs[i] == 0) {
            candidates.push_back(val[i]);
        }
    }
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    int K = (m_count + 1) / 2;
  
    int low = 0, high = (int)candidates.size() - 1;
    long long ans = candidates[0];
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        dfs(1, candidates[mid]);
        if (f[1] <= K) {
            ans = candidates[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
