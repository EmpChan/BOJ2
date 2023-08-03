#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int, int>;

int arr[101];
vector<info>tree[101];
int dist[101][101];
int maxi = 0,n;

void findminidist() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int  m, r,a,b,c;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i+1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = 100000;
		}
		dist[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	findminidist();
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m)tmp += arr[j];
		}
		maxi = max(maxi, tmp);
	}
	cout << maxi; 

	return 0;
}