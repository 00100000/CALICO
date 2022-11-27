#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

ll maxHL = 100001;

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> hfreq(maxHL);
	vector<ll> lfreq(maxHL);
	vector<ll> freq(maxHL);
	for (ll i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		hfreq[temp]++;
	}
	for (ll i = 0; i < n; i++) {
		ll temp;
		cin >> temp;
		lfreq[temp]++;
	}
	// prefix sums
	for (ll i = 1; i < maxHL; i++) hfreq[i] += hfreq[i - 1];
	for (ll i = 1; i < maxHL; i++) lfreq[i] += lfreq[i - 1];
	// number in each spot = prefix sums of heads - prefix sums of bottom
	for (ll i = 0; i < maxHL; i++) freq[i] = lfreq[i] - hfreq[i];
	for (ll i = 1; i < maxHL; i++) freq[i] += freq[i - 1];
	// two pollers
	ll a = 0, b = 1;
	for (ll i = 0; i < maxHL && b < maxHL; i++) {
		if (freq[b] - freq[a] == k) {
			cout << a + 1 << ' ' << b + 1;
			return;
		}
		if (freq[b] - freq[a] < k) b++;
		else a++;
	}
	cout << "IMPOSSIBLE";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
	return 0;
}
