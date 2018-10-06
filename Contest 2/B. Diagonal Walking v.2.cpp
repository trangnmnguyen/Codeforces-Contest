#include <bits/stdc++.h>
using namespace std;
int q;
long long n;
long long m;
long long k;

int main() {
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> q;
	for(int iQ = 1; iQ <= q; iQ++) {
		cin >> n >> m >> k;
		if(k < max(n, m)) {
			cout << "-1\n";
		}
		else if(n % 2 != m % 2) {
			cout << k - 1 << "\n";
		}
		else {
			if(max(n, m) % 2 == k % 2) {
				cout << k << "\n";
			}
			else {
				cout << k - 2 << "\n";
			}
		}
	}
	return 0;
}