#include <bits/stdc++.h>

using namespace std;

bool debug = false;

pair<int, int> findBWidth(int n, int d) {
	pair<int, int>res;
	res.first = -d;
	res.second = d;
	return res;
}

pair<int, int> findBLength(int n, int d) {
	pair<int, int>res;
	res.second = 2*n - d;
	res.first = d;
	return res;
}

bool checkbWidth(pair<int, int> grasshopperI, pair<int, int> bWidth) {
	int bGrasshopperWidth = grasshopperI.second - grasshopperI.first;
	if(debug) {
		cout << "bGrasshopperWidth: " << bGrasshopperWidth << endl;
	}
	if(bGrasshopperWidth <= bWidth.second && bGrasshopperWidth >= bWidth.first) {
		return true;
	}
	return false;
}

bool checkBLength(pair<int, int> grasshopperI, pair<int, int> bLength) {
	int bGrasshopperLength = grasshopperI.first + grasshopperI.second;
	if(debug) {
		cout << "bGrasshopperLength: " << bGrasshopperLength << endl;
	}
	if(bGrasshopperLength <= bLength.second	&& bGrasshopperLength >= bLength.first) {
		return true;
	}
	return false;
}

int main() {
	int n, d;
	cin >> n >> d;
	int m;
	cin >> m;
	vector<pair<int, int>>grasshopper(m);

    for(int i = 0; i < m; i++) {
		cin >> grasshopper[i].first >> grasshopper[i].second;
	}

	pair<int, int> bWidth = findBWidth(n, d);
	pair<int, int> bLength = findBLength(n, d);

	if(debug) {
		cout << "bWidth: " << bWidth.first << " " << bWidth.second << endl;
		cout << "bLength: " << bLength.first << " " << bLength.second << endl;
	}

	for(int i = 0; i < m; i++) {
		if(checkbWidth(grasshopper[i], bWidth) && checkBLength(grasshopper[i], bLength)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
