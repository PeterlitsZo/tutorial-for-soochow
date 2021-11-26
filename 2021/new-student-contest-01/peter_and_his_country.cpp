// By Peterlits Zo <peterlitszo@gmail.com>
// ^_^
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // input l, n and array A
    ll l;
    int n;
    scanf("%lld %d", &l, &n);
    constexpr int LEN = 100 + 16;
    static ll A[LEN];
    for (int i = 0; i < n; i ++) {
        scanf("%lld", &A[i]);
    }

    // try to find the max.
    ll ans = 0;
    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            int G = __gcd(A[i], A[j]);

            // get all div
            vector<int> divs;
            for(int k = 1; k * k <= G; k ++) {
                if(G % k == 0) {
                    divs.push_back(k);
                    if(k * k != G) divs.push_back(G / k);
                }
            }

            // get the element
            sort(divs.begin(), divs.end());
            auto ele_ptr = --upper_bound(divs.begin(), divs.end(), l);
            ans = max(ans, (ll)*ele_ptr);
        }
    }

    printf("%lld", ans);
    return 0;
}
