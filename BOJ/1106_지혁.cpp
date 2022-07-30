#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n;
	cin >> c >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	for (int i = 1; i <= 100000; i++) {
		for (int j = 0; j < n; j++) {
			if (i % vt[j].first == 0) {
				dp[i] = max(dp[i], (i / v[j].first) * v[j].second);
			}
			if (i - vt[j].first >= 0) {
				dp[i] = max(dp[i],dp[i - v[j].first] + v[j].second);
			}
		}
		if (c <= dp[i]) {
			cout << i;
			return 0;
		}
	}

	return 0;
}