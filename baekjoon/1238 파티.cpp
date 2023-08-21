#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 10000000

using namespace std;
using lld =long long;
using info = pair<int, int>;

vector<info>road[1001];
int t[1001];
int gox[1001];
int gohome[1001];
int n, m, x;

void sol(int k) {
	for (int i = 1; i <= n; i++) t[i] = INF;
	t[k] = 0;
	priority_queue<info, vector<info>, greater<info>>pq;
	for (auto i : road[k]) {
		pq.push(i);
		t[i.second] = i.first;
	}
	while (!pq.empty()) {
		int d = pq.top().second;
		int ti = pq.top().first;
		pq.pop();
		if (t[d] < ti)continue;
		for (auto i : road[d]) {
			int dd = i.second;
			int tt = ti + i.first;
			if (tt < t[dd]) {
				pq.push(make_pair(tt, dd));
				t[dd] = tt;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int a,b,c;
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		road[a].push_back(make_pair(c, b));
	}

	for (int i = 1; i <= n; i++) {
		sol(i);
		if (i != x) gox[i] = t[x];
		else {
			for (int i = 1; i <= n; i++) {
				gohome[i] = t[i];
			}
		}
	}

	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		maxi = max(maxi, gohome[i] + gox[i]);
	}

	cout << maxi;

	return 0;
}