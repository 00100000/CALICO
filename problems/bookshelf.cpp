#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

void solve() {
	int n, b, w, d;
	cin >> n >> b >> w >> d;
	int ans = (b + w + b) * b;
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		ans += h * b * 2;
		ans += (b + w + b) * b;
	}
	cout << ans * d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
	return 0;
}
