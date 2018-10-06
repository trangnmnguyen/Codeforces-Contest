#include <bits/stdc++.h>

using namespace std;

int main() {
	long long l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	long long i = l;
	while(i <= r) {
		cout << i << " " << i + 1 << endl;	
		i += 2;
	}
	return 0;
}	