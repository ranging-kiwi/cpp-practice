#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (s[i] - '0');
    }

    auto get_cost = [&](int l, int r, int target) {
        int len = r - l + 1;
        int ones = pre[r] - pre[l - 1];
        if (target == 1) return len - ones;
        return ones;
    };

    int min_ops = n;

    for (int i = 1; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            for (int k = j + 1; k <= n - 1; k++) {
                
                int cost1 = get_cost(1, i, 0) + get_cost(i + 1, j, 1) + 
                            get_cost(j + 1, k, 0) + get_cost(k + 1, n, 1);
                
                int cost2 = get_cost(1, i, 1) + get_cost(i + 1, j, 0) + 
                            get_cost(j + 1, k, 1) + get_cost(k + 1, n, 0);
                
                min_ops = min({min_ops, cost1, cost2});
            }
        }
    }

    cout << min_ops << endl;

    return 0;
}
