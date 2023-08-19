#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define INF 1000000000

using namespace std;
using lld = long long;
using info = pair<lld, int>;

vector<info>inf[1001];
int n;
lld costs[1001];

void sol() {
	int s, e;
	cin >> s >> e;
	for (int i = 0; i <= 1000; i++) costs[i] = INF;
	costs[s] = 0;

	priority_queue<info, vector<info>, greater<info>>pq;
	for (auto i : inf[s]) {
		pq.push(i);
	}

	while (!pq.empty()) {
		int d = pq.top().second;
		lld c = pq.top().first;
		costs[d] = min(costs[d], c);
		pq.pop();
		if (c > costs[d])continue;
		for (auto i : inf[d]) {
			int dd = i.second;
			lld cc = c + i.first;
			if (cc < costs[dd]) {
				costs[dd] = cc;
				pq.push(make_pair(cc, dd));
			}
		}
	}

	cout << costs[e];
}

int main() {

	int m,a,b;
	lld c;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		inf[a].push_back(make_pair(c, b));
	}

	sol();

	return 0;
}