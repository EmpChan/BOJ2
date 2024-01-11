#include <iostream>
#define MAX 500000000
using namespace std;
using lld = long long;

int n, m;
int info[500][500];
int dp[500][500];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> info[i][j];
		}
	}
	for (int i = 0; i < m; i++)dp[0][i] = info[0][i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = MAX;
			for (int k = 0; k < m; k++) {
				if (j == k)continue;
				dp[i][j] = min(dp[i][j], dp[i - 1][k] + info[i][j]);
			}
		}
	}

	int mini = MAX;
	for (int i = 0; i < m; i++) {
		mini = min(mini, dp[n-1][i]);
	}

	cout << mini;
	
	return 0;
}