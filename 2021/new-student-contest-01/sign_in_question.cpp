#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, mod = 998244353;
char s[N];
int ans[N], dp[N], res;

int main(void) {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '6') continue;
		for (int j = i - 1; j >= 0; j--) {
			if (s[j] == '6') continue;
			dp[i] += dp[j]; dp[i] %= mod;
			ans[i] += (1ll * 10 * ans[j] + 1ll * (s[i] - '0') * dp[j]) % mod; ans[i] %= mod;
			if (s[j] == s[i]) break;
		}
		res += ans[i]; res %= mod;
	}
	cout << res << endl;
	return 0;
}