#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;
using lld = long long;
using place = pair<int, int>;

bool visit[300][300];

void sol() {
	
	place dest;
	int n, cnt = 0;
	int a, b;
	int dx[] = { -2,-2,-1,-1,1,1,2,2, };
	int dy[] = { -1,1,-2,2,-2,2,-1,1 };
	cin >> n >> a >> b;
	queue < place>q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
	q.push(make_pair(a, b));
	visit[a][b] = 1;
	cin >> a >> b;
	dest = make_pair(a, b);
	while (!q.empty()) {
		cnt++;
		queue<place>tmp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			if (x == dest.first && y == dest.second) {
				cout << cnt - 1 << '\n';
				return;
			}
			q.pop();
			for (int i = 0; i < 8; i++) {
				int xx = dx[i] + x;
				int yy = dy[i] + y;
				if (xx < 0 || xx >= n || yy < 0 || yy >= n)continue;
				if (visit[xx][yy])continue;
				if (xx == dest.first && yy == dest.second) {
					cout << cnt << '\n';
					return;
				}
				visit[xx][yy] = 1;
				tmp.push(make_pair(xx, yy));
			}
		}
		swap(tmp, q);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--)sol();
	
	return 0;
}