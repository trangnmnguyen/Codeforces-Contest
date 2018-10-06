#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int totalEasy = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == 1) {
			totalEasy = 1;
			break;
		}
	}

	if(totalEasy == 0) {
		cout << "EASY" << endl;
	} else {
		cout << "HARD" << endl;
	}
	return 0;
}
