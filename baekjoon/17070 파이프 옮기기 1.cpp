#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000000

using namespace std;
using lld = long long;
using place = pair<int, int>;
using info = pair<int, place>;

int n;
bool map[17][17];

bool check(info a, int d) {
	if (d <= 0 || d >= 4)return 0;
	int x = a.second.first;
	int y = a.second.second;
	if (x >= n || y >= n)return 0;
	if (d == 1) {
		if (!map[x][y + 1])return 0;
		else return 1;
	}
	else if (d == 2) {
		if (!map[x][y + 1] || !map[x + 1][y] || !map[x + 1][y + 1])return 0;
		else return 1;
	}
	else {
		if (!map[x + 1][y])return 0;
		else return 1;
	}
}

void sol() {
	int ans = 0;
	queue<info>q;
	q.push(make_pair(1, make_pair(0, 1)));
	while (!q.empty()) {
		int cond = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		for (int i = cond - 1; i <= cond + 1; i++) {
			int xx = x;
			int yy = y;
			if (check(q.front(), i)) {
				if (i == 1) {
					yy++;
				}
				else if (i == 2) {
					yy++;
					xx++;
				}
				else {
					xx++;
				}
				if (xx == n - 1 && yy == n - 1)ans++;
				else {
					q.push(make_pair(i, make_pair(xx, yy)));
				}
			}
		}
		q.pop();
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			map[i][j] = !map[i][j];
		}
	}
	sol();

	return 0;
}