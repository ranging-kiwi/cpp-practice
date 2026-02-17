#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// 获取所有可能的子序列及其对应的删除步数
void get_subs(string s, unordered_map<long long, int> &subs) {
    int n = s.size();
    for (int i = 1; i < (1 << n); ++i) {
        string sub = "";
        int deleted = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> (n - 1 - j)) & 1) sub += s[j];
            else deleted++;
        }
        if (sub[0] == '0') continue; // 排除前导零
        long long val = stoll(sub);
        // 如果同一个数字有多种删除方式，保留删除步数最少的
        if (subs.find(val) == subs.end() || deleted < subs[val]) {
            subs[val] = deleted;
        }
    }
}

int main() {
    string sa, sb;
    if (!(cin >> sa >> sb)) return 0;

    unordered_map<long long, int> subs_a, subs_b;
    get_subs(sa, subs_a);
    get_subs(sb, subs_b);

    int min_ops = INT_MAX;

    // 交叉比对两个子序列集合
    for (auto const& [val_a, ops_a] : subs_a) {
        for (auto const& [val_b, ops_b] : subs_b) {
            if (val_a % val_b == 0 || val_b % val_a == 0) {
                if (ops_a + ops_b < min_ops) {
                    min_ops = ops_a + ops_b;
                }
            }
        }
    }

    if (min_ops == INT_MAX) cout << -1 << endl;
    else cout << min_ops << endl;

    return 0;
}
