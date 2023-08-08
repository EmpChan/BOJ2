#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10000000000

using namespace std;
using info = pair<int, int>;
using lld = long long;

int ans[10001];
vector<int>tmp[3];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		tmp[k % 3].push_back(k);
	}

	if (tmp[0].size() > (n + 1) / 2) {
		cout << -1;
		return 0;
	}
	else if (tmp[0].size() == 0 && tmp[1].size() && tmp[2].size()) {
		cout << -1;
		return 0;
	}
	while (tmp[0].size() > 1 && tmp[1].size()) {
		cout << tmp[0][tmp[0].size() - 1] << ' ';
		cout << tmp[1][tmp[1].size() - 1] << ' ';
		tmp[0].pop_back();
		tmp[1].pop_back();
	}
	while (tmp[1].size()) {
		cout << tmp[1][tmp[1].size() - 1] << ' ';
		tmp[1].pop_back();
	}
	while (tmp[0].size()&& tmp[2].size()) {
		cout << tmp[0][tmp[0].size() - 1] << ' ';
		cout << tmp[2][tmp[2].size() - 1] << ' ';
		tmp[0].pop_back();
		tmp[2].pop_back();
	}
	if(tmp[0].size())cout << tmp[0][tmp[0].size() - 1] << ' ';
	while (tmp[2].size()) {
		cout << tmp[2][tmp[2].size() - 1] << ' ';
		tmp[2].pop_back();
	}
	return 0;
}