#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void) {
    int T;
    cin >> T;
    while (T--) {
        ll l, r, n;
        cin >> l >> r >> n;
        if (n % (l + r) < l) puts("Bob");
        else puts("Alice");
    }
    return 0;
}