#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 10000000

using namespace std;
using lld =long long;
using info = pair<int, int>;

int arr[400];
lld ans = 0;

void sol(int n) {
	if (n == 1)return;
	if (n == 2) {
		ans = arr[0] + arr[1];
		return;
	}
	int t = n;
	while (t > 1) {
		int d = 0;
		lld tmp = arr[d] + arr[d + 1];
		for (int i = 1; i < t - 1; i++) {
			if (tmp > arr[i] + arr[i + 1]) {
				tmp = arr[i] + arr[i + 1];
				d = i;
			}
		}
		ans += tmp;
		t--, arr[d] = max(arr[d],arr[d+1]);
		for (int i = d+1; i < t; i++) {
			arr[i] = arr[i + 1];
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	sol(n);
	cout << ans;

	return 0;
}