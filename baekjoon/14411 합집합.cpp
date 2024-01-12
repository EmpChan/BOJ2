#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 500000000

using namespace std;
using lld = long long;
using info = pair<lld, lld>;

priority_queue<info>pq;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n;
	lld s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push({ y/2,x/2 });
	}
	int before = 0;
	while (!pq.empty()) {
		if (pq.top().second <= before) {
			pq.pop();
			continue;
		}
		s += (pq.top().second - before) * pq.top().first;
		before = pq.top().second;
		pq.pop();
	}

	cout << s * 4;

	return 0;
}