#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
using lld =long long;
using info = pair<int, int>;

vector<info>tree[10001];
int ans = 0;

int sorting(int node) {
	if (!tree[node].size())return 0;
	priority_queue<int>pq;
	int maxi = 0,tmp = 0;
	for (auto i : tree[node]) {
		int d = i.second + sorting(i.first);
		maxi = max(d,maxi);
		pq.push(d);
	}
	for (int i = 0; !pq.empty() && i < 2; i++) {
		tmp += pq.top();
		pq.pop();
	}
	ans = max(ans, tmp);
	return maxi;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,a,b,c;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		tree[a].push_back(make_pair(b, c));
	}

	sorting(1);
	cout << ans;

	return 0;
}