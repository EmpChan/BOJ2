#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#define INF 1000000000

using namespace std;
using lld = long long;
using info = pair<lld, int>;

int n;
int arr[9];
int ans[8];

void nnms(int c, int k) {
	if (c == k) {
		for (int i = 0; i < c; i++) cout << arr[ans[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		bool flag = 0;
		for (int j = 0; j < c; j++) {
			if (ans[j] == i) {
				flag = 1;
				break;
			}
		}
		if (flag)continue;
		ans[c] = i;
		nnms(c + 1, k);
		while (i < n && arr[i] == arr[i + 1])i++;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int  m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	nnms(0, m);

	return 0;
}