#include <bits/stdc++.h>

using namespace std;

bool debug = false;

bool checkSegments(int i, string ticket, int equalSum, int n) {
    if(debug) {
        cout << "i: " << i << " ticket: " << ticket << " equalSum: " << equalSum << " n: " << n << endl;
    }

    if(i >= n) {
        return false;
    }

	int tmpEqualSum = 0;
	for(int j = i + 1; j < n; j++) {
		int curNumber = ticket[j] - '0';
		if(curNumber <= equalSum) {
			tmpEqualSum += curNumber;
		} else {
			return false;
		}
        if(debug) {
            cout << "tmpEqualSum: " << tmpEqualSum << " j: " << j << " n: " << n << " equalSum: " << equalSum << endl;
        }

		if(tmpEqualSum > equalSum) {
			return false;
		} else if(tmpEqualSum == equalSum) {
		    if(j == n - 1) {
                return true;
            } else {
                if(checkSegments(j, ticket, equalSum, n)) {
                    return true;
                }
            }
		}
	}

	return false;
}

int main() {
	int n;
	cin >> n;
	string ticket;
	cin >> ticket;

	int equalSum = 0;
	for(int i = 0; i < n; i++) {
		equalSum += ticket[i] - '0';
		if(checkSegments(i, ticket, equalSum, n)) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
