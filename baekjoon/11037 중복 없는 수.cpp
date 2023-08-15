#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 987654321

using namespace std;
using lld = long long;

vector<int>tmp;
int r[9];

void getit(int a, int k) {
	if (k == a) {
		int rr = 0;
		for (int i = 0; i < k; i++)rr = rr * 10 + r[i];
		tmp.push_back(rr);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			bool flag = 0;
			for (int j = 0; j < a; j++) {
				if (r[j] == i) {
					flag = 1;
					break;
				}
			}
			if (!flag) {
				r[a] = i;
				getit(a + 1, k);
			}
		}
	}
}

void sol() {
	for (int i = 1; i <= 9; i++) {
		getit(0,i);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	sol();
	sort(tmp.begin(), tmp.end());
	while (1) {
		int n;
		cin >> n;
		if (cin.eof())break;
		if (n >= MAX)cout << 0 << '\n';
		else {
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp[i] > n) {
					cout << tmp[i] << '\n';
					break;
				}
			}
		}
	}


	return 0;
}