#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <set>
#define MAX 10007

using namespace std;
using lld = long long;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) cout << ' ';
		for (int j = 0; j < i + 1; j++)cout << '*';
		cout << '\n';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++)cout << ' ';
		for (int j = 0; j < n - i - 1; j++) cout << '*';
		cout << '\n';
	}
	return 0;
}