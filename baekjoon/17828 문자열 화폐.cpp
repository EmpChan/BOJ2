#include <iostream>

using namespace std;
using lld = long long;

lld n, val;
string ans;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> val;
	if (n * 26 < val || n > val) {
		cout << "!";
		return 0;
	}
	while (val>0) {
		if (val > n+25) {
			ans += "Z";
			val -= 26;
			n--;
		}
		else if(val >n){
			ans += (char)('A' + val - n);
			val -=(val-n+1);
			n--;
		}
		else {
			for (int i = 0; i < val; i++) {
				ans += "A";
			}
			val = 0;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}