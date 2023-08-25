#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000000

using namespace std;
using lld =long long;
using info = pair<int, int>;

bool visit[26];
char map[20][20];
int ans = 0;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

void dfs(int t, int x, int y) {
	ans = max(ans, t);
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + dx[i], yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		if (visit[map[xx][yy] - 'A'])continue;
		visit[map[xx][yy] - 'A'] = 1;
		dfs(t + 1, xx, yy);
		visit[map[xx][yy] - 'A'] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < m; j++) map[i][j] = a[j];
	}
	visit[map[0][0] - 'A'] = 1;
	dfs(1,0, 0);
	cout << ans;

	return 0;
}