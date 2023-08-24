#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000000

using namespace std;
using lld =long long;
using info = pair<int, int>;

int n, m;
bool cond[100][100];
int map[100][100];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
queue<info>q;

void checkit(int d, int x,int y) {
	if (map[x][y])return;
	if ((d == 1 || d== 3) && cond[x][y] == 1)return;
	if (d == 2 && cond[x][y] == 0) return;
	map[x][y] = d;
	for (int i = 0; i < 4; i++) {
		int xx = x+dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		checkit(d, xx, yy);
	}
}
void threeToOne(int x, int y) {
	map[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
		if (map[xx][yy] != 3) continue;
		threeToOne(xx, yy);
	}
}

void sol() {
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		queue<pair<bool,info>>tmp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			int c = 0;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = dx[i] + x;
				int yy = dy[i] + y;
				if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
				if (map[xx][yy] == 1) c++;
			}
			if (c >= 2)tmp.push(make_pair(1, make_pair(x, y)));
			else tmp.push(make_pair(0, make_pair(x, y)));
		}
		while (!tmp.empty()) {
			bool d = tmp.front().first;
			info in = tmp.front().second;
			tmp.pop();
			if (d == 0)q.push(in);
			else {
				for (int i = 0; i < 4; i++) {
					int xx = dx[i] + in.first;
					int yy = dy[i] + in.second;
					if (xx < 0 || xx >= n || yy < 0 || yy >= m)continue;
					if (map[xx][yy] == 3) {
						threeToOne(xx, yy);
					}
				}
				map[in.first][in.second] = 1;
			}
		}
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cond[i][j];
			if (cond[i][j])q.push(make_pair(i, j));
		}
	}
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j])continue;
			if (cond[i][j] == 0 && !flag) {
				checkit(1, i, j);
				flag = 1;
			}
			if (cond[i][j] == 0) {
				checkit(3, i, j);
			}
			if (cond[i][j]) {
				checkit(2, i, j);
			}
		}
	}
	sol();

	return 0;
}