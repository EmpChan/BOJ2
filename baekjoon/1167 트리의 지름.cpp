#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using lld =long long;
using info = pair<int, int>;

vector<info>tree[100001];
bool visit[100001];
int ans = 0;

int sorting(int node) {
	priority_queue<int>pq;
	for (auto i : tree[node]) {
		if (visit[i.first])continue;
		visit[i.first] = 1;
		int d = i.second + sorting(i.first);
		pq.push(d);
	}
	int maxi = 0,tmp = 0;
	if (!pq.empty()) {
		maxi = pq.top();
		for (int i = 0; !pq.empty() && i < 2; i++) {
			tmp += pq.top();
			pq.pop();
		}
		ans = max(ans, tmp);
	}

	return maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,a=0,b,node;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> node >> a;
		while (a != -1) {
			cin >> b;
			tree[node].push_back(make_pair(a, b));
			cin >> a;
		}
	}
	visit[1] = 1;
	sorting(1);

	cout << ans;

	return 0;
}