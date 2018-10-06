#include <bits/stdc++.h>

using namespace std;

bool debug = false;

int main() {
	int n, L, a;
	cin >> n >> L >> a;

	vector<int> t(n), l(n);
	for(int i = 0; i < n; i++) {
		cin >> t[i] >> l[i];
	}

	int res = 0;

	if(n == 0) {
		res = L / a;
		cout << res << endl;
		return 0;
	}

	int endServicePrev = 0;
	int startServiceCur = t[0];

	for(int i = 0; i < n; i++) {

		if(i > 0) {
			endServicePrev = t[i - 1] + l[i - 1];
			startServiceCur = t[i];
		}

		if(debug) {
            cout << "i: " << i << " startServiceCur: " << startServiceCur << " endServicePrev: " << endServicePrev << " res: " << res << endl;
        }

		if((startServiceCur - endServicePrev) >= a) {
			res += (startServiceCur - endServicePrev) / a;
		}
	}

	if((L - t[n - 1] - l[n - 1]) >= a) {
		res += (L - t[n - 1] - l[n - 1]) / a;
	}

	cout << res << endl;

	return 0;
}
