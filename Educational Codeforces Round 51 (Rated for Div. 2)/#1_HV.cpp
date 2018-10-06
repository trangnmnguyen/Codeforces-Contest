#include <bits/stdc++.h>
using namespace std;
int nTest;
string s;
string ans;
int minDif;

bool isValid(const string& s) {
	bool hasLower = false;
	bool hasUpper = false;
	bool hasDigit = false;
	for(char ch : s) {
		if(ch >= 'a' && ch <= 'z') {
			hasLower = true;
		}
		if(ch >= 'A' && ch <= 'Z') {
			hasUpper = true;
		}
		if(ch >= '0' && ch <= '9') {
			hasDigit = true;
		}
	}
	return hasLower && hasUpper && hasDigit;
}

int getDif(const string& s, const string& t) {
	int firstDif = -1;
	int lastDif = -1;
	for(int i = 0; i < s.size(); i++) {
		char chS = s[i];
		char chT = t[i];
		if(chS != chT) {
			if(firstDif == -1) {
				firstDif = i;
			}
			lastDif = i;
		}
	}
	if(firstDif == -1) {
		return 0;
	}
	return lastDif - firstDif + 1;
}

int main() {
	cin >> nTest;
	for(int iTest = 0; iTest < nTest; iTest++) {
		cin >> s;
		ans = "";
		minDif = 0;
		for(char ch0 : {'0', 'a', 'A', s[0]}) {
			for(char ch1 : {'0', 'a', 'A', s[1]}) {
				string newS;
				newS += ch0;
				newS += ch1;
				newS += s.substr(2, s.size() - 2);
				if(isValid(newS)) {
					int dif = getDif(s, newS);
					if(ans.empty() || dif < minDif) {
						ans = newS;
						minDif = dif;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}