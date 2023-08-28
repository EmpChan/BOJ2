#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#define INF 1000000000
#define MAX 1000

using namespace std;
using lld =long long;
using info = pair<int, int>;
using vect = vector<vector<int>>;
vect matrix;
vect ans;
lld n, m;

vect sq(vect a, vect b) {
	vect tmp;
	tmp.resize(n);
	for (int i = 0; i < n; i++) tmp[i].resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				tmp[i][j] += a[i][k] * b[k][j];
			}
			tmp[i][j] %= MAX;
		}
	}
	return tmp;
}

vect sol(lld m) {
	if (m > 2) {
		vect tt = sol(m / 2);
		if (m % 2 == 0) {
			
			return sq(tt,tt);
		}
		else return sq(sq(tt, tt), matrix);
	}
	else {
		if (m == 1) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) matrix[i][j]%=MAX;
			}
			
			return matrix;
		}
		else {
			vect tmp;
			tmp.resize(n);
			for (int i = 0; i < n; i++) tmp[i].resize(n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						tmp[i][j] += matrix[i][k] * matrix[k][j];
					}
					tmp[i][j] %= MAX;
				}
			}
			
			return tmp;
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	matrix.resize(n);
	for (int i = 0; i < n; i++) {
		matrix[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	}
	ans = sol(m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}