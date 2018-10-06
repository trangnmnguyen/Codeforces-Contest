#include <bits/stdc++.h>

using namespace std;

bool debug = false;

bool checkPartSimilar(vector<vector<char>>&forgeSignature, vector<vector<char>>&signature, int i, int j) {
	for(int a = i - 1; a <= i + 1; a++) {
		for(int b = j - 1; b <= j + 1; b++) {
			
			if(forgeSignature[a][b] != signature[a][b]) {
				return false;
			}
		}
	}
	return true;
}

void changeSignature(vector<vector<char>>&forgeSignature, int i, int j) {
	for(int a = i - 1; a <= i + 1; a++) {
		for(int b = j - 1; b <= j + 1; b++) {
			if(a == i && b == j && forgeSignature[a][b] != '#') {
				forgeSignature[a][b] = '.';
			} else {
				forgeSignature[a][b] = '#';
			}
		}
	}
	return;
}

bool checkSignatureSimilar(vector<vector<char>>&signature, vector<vector<char>>&forgeSignature, int n, int m) {
	for(int a = 0; a < n; a++) {
		for(int b = 0; b < m; b++) {
			if(signature[a][b] != forgeSignature[a][b]) {
				return false;
			}
		}
	}
	return true;
}

vector<vector<char>>getPartial(vector<vector<char>>&signature, int i, int j) {
	vector<vector<char>>partial(3, vector<char>>(3));
	for(int a = i - 1; a <= i + 1; a++) {
		for(int b = j - 1; b <= j + 1; b++) {
			partial[a][b] = signature[a][b];
		}
	}
	return partial;
}

void reverseSignature(vector<vector<char>>&forgeSignature, int i, int j, vector<vector<char>>&tmpSignature) {
	for(int a = i - 1; a <= i + 1; a++) {
		for(int b = j - 1; b <= j + 1; b++) {
			forgeSignature[a][b] = tmpSignature[a - (i - 1)][b - (j - 1)];
		}
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>>signature(n, vector<char>(m));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> signature[i][j];
		}
	}

	vector<vector<char>>tmpSignature(3, vector<char>(3));
	vector<vector<char>>forgeSignature(n, vector<char>(m));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(i - 1 >= 0 && i + 1 < n && j - 1 >= 0 && j + 1 < m) {
				tmpSignature = getPartial(forgeSignature, i, j);
				changeSignature(forgeSignature, i, j);
				if(!checkPartSimilar(signature, forgeSignature, i, j)) {
					reverseSignature(forgeSignature, i, j, tmpSignature);
				}
			}
		}
	}

	if(checkSignatureSimilar(signature, forgeSignature, n, m)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}