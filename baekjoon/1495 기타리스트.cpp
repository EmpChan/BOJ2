#include <iostream>
#include <set>

using namespace std;

int arr[50];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,s,m;
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	set<int>se;
	se.insert(s);
	for (int i = 0; i < n; i++) {
		set<int>tmp;
		for (auto j : se) {
			if (j + arr[i] <= m)tmp.insert(j + arr[i]);
			if (j - arr[i] >= 0)tmp.insert(j - arr[i]);
		}
		swap(tmp, se);
		if (se.empty()) {
			cout << -1 << '\n';
			return 0;
		}
	}
	
	cout << *se.rbegin();

	return 0;
}