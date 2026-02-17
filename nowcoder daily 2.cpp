#include <iostream>
#include <cstdio>
using namespace std;
void solve() {
    int n, l, r;
    if (scanf("%d %d %d", &n, &l, &r) != 3) return;
    int mod = n % (l + r);
    if (mod >= l) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
