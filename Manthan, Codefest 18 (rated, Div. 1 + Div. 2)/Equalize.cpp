#include <bits/stdc++.h>

using namespace std;
int n;
string a;
string b;
int ans;

int main() {
	cin >> n;
	cin >> a;
	cin >> b;
	ans = 0;
	for(int i = 0; i < a.size(); i++) {
		if(i + 1 < a.size() && a[i] != a[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) {
			ans++;
			swap(a[i], a[i + 1]);
		}
		else {
			if(a[i] != b[i]) {
				ans++;
				a[i] = b[i];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
