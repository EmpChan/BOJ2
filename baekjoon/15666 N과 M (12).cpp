#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000000

using namespace std;
using lld = long long;
using info = pair<lld, int>;

int  n;
set<int>arr;
int ans[8];

void nnms(int c, int k) {
	if (c == k) {
		for (int i = 0; i < c; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (auto i : arr) {
		bool flag = 0;
		for (int j = 0; j < c; j++) {
			if (i < ans[j]) {
				flag = 1;
				break;
			}
		}
		if (flag)continue;
		ans[c] = i;
		nnms(c + 1, k);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int m,d;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> d;
		arr.insert(d);
	}
	nnms(0, m);

	return 0;
}