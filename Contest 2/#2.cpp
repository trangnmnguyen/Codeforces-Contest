#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool debug = false;
	int n, m;
	cin >> n;

	vector<long long int>a(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cin >> m;

	vector<long long int>b(m, 0);
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int i = 0, j = 0;
	int cnt = 0;
	while(i < n && j < m) {
        if(debug) {
            cout << "a[i]: " << a[i] << " b[j]: " << b[j] << " i: " << i << " j: " << j << endl;
        }
		if(a[i] == b[j]) {
			i++;
			j++;
			cnt++;
		} else if(a[i] < b[j]) {
			i++;
			if(i >= n) {
				break;
			}
			a[i] = a[i - 1] + a[i];
			while(i < n && j < m && a[i] < b[j]) {
				if(debug) {
		            cout << 1 << "a[i]: " << a[i] << " b[j]: " << b[j] << " i: " << i << " j: " << j << endl;
		        }
				i++;
				a[i] = a[i - 1] + a[i];
			}
		} else {
			j++;
			if(j >= m) {
				break;
			}
			b[j] = b[j] + b[j - 1];
			while(i < n && j < m &&  b[j] + b[j - 1] < a[i]) {
				if(debug) {
		            cout << 2 << "a[i]: " << a[i] << " b[j]: " << b[j] << " i: " << i << " j: " << j << endl;
		        }
				j++;
				b[j] = b[j - 1] + b[j];
			}
		}
		if(debug) {
            cout << 3 << "a[i]: " << a[i] << " b[j]: " << b[j] << " i: " << i << " j: " << j << endl;
        }
	}
	if(i == n && j == m) {
		cout << cnt << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
