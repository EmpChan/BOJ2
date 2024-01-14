#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500000000

using namespace std;
using lld = long long;
using info = pair<lld, lld>;

lld dp[1500001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;

		dp[i] = max(dp[i], dp[i - 1]);
		if (i + t-1 > n)continue;
		dp[i + t-1] = max(dp[i + t-1], dp[i - 1] + p);
	}

	cout << dp[n];

	return 0;
}