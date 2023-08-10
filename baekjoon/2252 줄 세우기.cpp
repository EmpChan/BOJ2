#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using info = pair<int, int>;

int degree[32001];
vector<int>lessThan[32001];
vector<int>out;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m,a,b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		lessThan[a].push_back(b);
		degree[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0)out.push_back(i);
	}

	while (!out.empty()) {
		int tmp = out[out.size() - 1];
		out.pop_back();
		cout << tmp << ' ';
		for (auto i : lessThan[tmp]) {
			degree[i]--;
			if (degree[i] <= 0)out.push_back(i);
		}
	}

	return 0;
}