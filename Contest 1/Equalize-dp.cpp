#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	vector<int>minCost(n, 0);
	recursive(minCost, n, a, b, 0, 0);
	for(int i = 0; i < n; i++) {
		
	}
	return 0;
}
