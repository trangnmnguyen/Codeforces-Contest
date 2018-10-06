#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int>arr(n, 0);
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if(n == 1) {
		cout << abs(arr[0] - s);
		return 0;
	} 

	sort(arr.begin(), arr.begin() + n);
	int med = n / 2;
	long long minOp = abs(s - arr[med]);
	//cout << minOp << endl;
	for(int i = med - 1; i >= 0; i--) {
		if(arr[i] > s) {
			minOp += abs(s - arr[i]);
			//cout << minOp << endl;
		} else {
			break;
		}
	}

	for(int i = med + 1; i < n; i++) {
		if(arr[i] < s) {
			minOp += abs(s - arr[i]);
			//cout << minOp << endl;
		} else {
			break;
		}
	}

	cout << minOp << endl;

	return 0;
}
