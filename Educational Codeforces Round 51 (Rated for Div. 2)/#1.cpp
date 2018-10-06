#include <bits/stdc++.h>

using namespace std;

bool checkUpperCase(string password) {
	for(int i = 0; i < password.size(); i++) {
		// if(password[i] >= 'A' && password[i] <= 'Z') {
		// 	return true;
		// }
		if(isupper(password[i])) {
			return true;
		}
	}
	return false;
}

bool checkLowerCase(string password) {
	for(int i = 0; i < password.size(); i++) {
		// if(password[i] >= 'a' && password[i] <= 'z') {
		// 	return true;
		// }
		if(islower(password[i])) {
			return true;
		}
	}
	return false;
}

bool checkInt(string password) {
	for(int i = 0; i < password.size(); i++) {
		// if(password[i] >= '0' && password[i] <= '9') {
		// 	return true;
		// }
		if(isdigit(password[i])) {
			return true;
		}
	}
	return false;
}

string changeUpperPassword(string password, int indexChange) {
	password[indexChange] = 'A';
	return password;
}

string changeLowerPassword(string password, int indexChange) {
	password[indexChange] = 'a';
	return password;
}

string changeIntPassword(string	password, int indexChange) {
	password[indexChange] = '0';
	return password;
}

int main() {
	int n;
	cin >> n;
	vector<string>pas(n);
	for(int i = 0; i < n; i++) {
		cin >> pas[i];
	}

	for(int i = 0; i < n; i++) {
		if(!checkUpperCase(pas[i])) {
			if(checkInt(pas[i]) && checkLowerCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeUpperPassword(pas[i], j);
					if(checkUpperCase(newPassword) && checkInt(newPassword) && checkLowerCase(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkInt(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeUpperPassword(pas[i], j);
					if(checkUpperCase(newPassword) && checkInt(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkLowerCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeUpperPassword(pas[i], j);
					if(checkUpperCase(newPassword) && checkLowerCase(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			}
		}

		if(!checkLowerCase(pas[i])) {
			if(checkInt(pas[i]) && checkUpperCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeLowerPassword(pas[i], j);
					if(checkInt(newPassword) && checkLowerCase(newPassword) && checkUpperCase(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkInt(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeLowerPassword(pas[i], j);
					if(checkInt(newPassword) && checkLowerCase(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkUpperCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeLowerPassword(pas[i], j);
					if(checkUpperCase(newPassword) && checkLowerCase(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			}			
		}

		if(!checkInt(pas[i])) {
			if(checkUpperCase(pas[i]) && checkLowerCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeIntPassword(pas[i], j);
					if(checkLowerCase(newPassword) && checkUpperCase(newPassword) && checkInt(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkUpperCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeIntPassword(pas[i], j);
					if(checkUpperCase(newPassword) && checkInt(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			} else if(checkLowerCase(pas[i])) {
				for(int j = 0; j < pas[i].size(); j++) {
					string newPassword = changeIntPassword(pas[i], j);
					if(checkLowerCase(newPassword) && checkInt(newPassword)) {
						pas[i] = newPassword;
						break;
					}
				}
			}
		}
	}

	for(int i = 0; i < n; i++) {
		cout << pas[i] << endl;
	}

	return 0;
}