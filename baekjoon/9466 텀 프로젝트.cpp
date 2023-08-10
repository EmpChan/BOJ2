#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using info = pair<int, int>;

bool visit[100001];
int arr[100001];
vector<int>teammate(100001);

int sol(int n) {
	int r = 0;
	for (int i = 1; i <= n; i++)visit[i] = 0;
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		int tmp = arr[i], k = 0;
		visit[i] = 1;
		teammate[k++] = i;
		while (!visit[tmp]) {
			teammate[k++] = tmp;
			visit[tmp] = 1;
			tmp = arr[tmp];
		}
		if (teammate[k - 1] != tmp)teammate[k] = tmp;
		for (int j = 0; teammate[j] != tmp; j++) r++;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)cin >> arr[i];
		cout << sol(n) << '\n';
	}
	
	return 0;
}