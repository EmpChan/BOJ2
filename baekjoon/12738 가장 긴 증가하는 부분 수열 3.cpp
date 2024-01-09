#include <iostream>

using namespace std;

int n,s;
int arr[1000001];
int tmp[1000001];

void find(int item) {
	int left = 0, right = s;
	while (left < right) {
		int mid = (left + right) / 2;
		if (tmp[mid] > item) {
			right = mid;
		}
		else if(tmp[mid] < item){
			left = mid + 1;
		}
		else {
			left = mid;
			right = mid;
		}
	}
	if (left == s)tmp[s++] = item; 
	else tmp[left] = min(tmp[left],item);
	/*cout << item << ' ' << left << ' ' << right << '\n';
	for (int i = 0; i < s; i++) {
		cout << tmp[i] << ' ';
	}
	cout << '\n';*/
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++)find(arr[i]);
	cout << s;

	return 0;
}