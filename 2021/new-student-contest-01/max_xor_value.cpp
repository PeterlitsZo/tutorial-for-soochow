#include<bits/stdc++.h>
using namespace std;

int n;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	int cnt = 0;
	while (n) {
		cnt++; n >>= 1;
	}
	cout << (1 << cnt) - 1 << endl;
	return 0;
}