#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000

using namespace std;
using info = pair<int, pair<int,int>>;

int n, m, a, b, c;
vector<info>need;
priority_queue<info, vector<info>, greater<info>>pq;
int parent[100001];
bool visit[100001];

int Find(int t) {
	vector<int>v;
	v.push_back(t);
	int k = parent[t];
	while (k != parent[k]) {
		v.push_back(k);
		k = parent[k];
	}
	for (auto i : v)parent[i] = k;
	return k;
}

void Union(int a, int b) {
	parent[Find(b)] = Find(a);
}

void sol() {
	while (!pq.empty()) {
		info tmp = pq.top();
		pq.pop();
		int a = tmp.second.first;
		int b = tmp.second.second;
		if (!visit[a] || !visit[b]) {
			need.push_back(tmp);
			visit[a] = 1;
			visit[b] = 1;
			Union(a, b);
		}
		else if (Find(a) != Find(b)) {
			need.push_back(tmp);
			Union(a, b);
		}
	}
}




int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sol();
	for (int i = 0; i < need.size() - 1; i++){
		ans += need[i].first;
	}

	cout << ans; 
	
	return 0;
}