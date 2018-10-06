#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int sum_packets = 0, i = 1, amt_packets = 0;
	while(sum_packets < n) {
		sum_packets += i;
		i++;
		amt_packets++;
	}

	cout << amt_packets;
	return 0;
}
