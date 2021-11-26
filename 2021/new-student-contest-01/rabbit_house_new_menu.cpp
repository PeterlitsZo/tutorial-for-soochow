#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
int n;
map<pair<int, int>, int> mp;
int cntx[N], cnty[N];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1, x, y; i <= n; i++) {
		cin >> x >> y;
		cntx[x]++; cnty[y]++;
		mp[{x, y}]++;
	}
	ll ans = 1ll * n * (n - 1) * (n - 2) / 6;
	for (auto it: mp) {
		int x = it.first.first, y = it.first.second, cnt = it.second;
		ans -= 1ll * cnt * (cnt - 1) * (cnt - 2) / 6;
		ans -= 1ll * cnt * (cnt - 1) / 2 * (n - cnt);
		ans -= 1ll * cnt * (cntx[x] - cnt) * (cnty[y] - cnt);
	}
	cout << ans << endl;
	return 0;
}