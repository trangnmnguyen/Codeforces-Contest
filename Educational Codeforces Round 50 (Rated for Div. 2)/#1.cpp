#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int n, k;
	cin >> n;
	cin >> k;

	if(n == 0 || k == 0) {
		cout << 0 << endl;
		return 0;
	}

	long long int res = 0;
	//cout << n << ' ' << k << endl;
	if(k <= n) {
		res = 1;
	} else {
		if(k % n == 0) {
			res = k / n;
		} else {
			res = k / n + 1;
		}
	}
	cout << res << endl;
	return 0;
}
