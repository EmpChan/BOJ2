#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using lld = long long;

lld sol(lld n) {
	lld s = 0;
	lld tmp = 1;
	while (tmp <= n) {
		lld t = n - tmp + 1;
		lld k = t % (tmp*2);
		s += ((t / (tmp * 2)) *(tmp))+min(k,tmp);
		tmp *= 2;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	lld n, m;
	cin >> n >> m;
	cout << sol(m) - sol(n - 1);
	return 0;
}