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
	priority_queue<int, vector<int>, greater<int>>pq;
	int n,tmp;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> tmp;
		pq.push(tmp);
		if (pq.size() > n)pq.pop();
	}
	cout <<  pq.top();

	return 0;
}