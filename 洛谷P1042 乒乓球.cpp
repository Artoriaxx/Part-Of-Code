#include<bits/stdc++.h>
using namespace std;
char s[2550][30];
int main() {
	int n = 1;
	int flag = 0;
	while (1) {
		scanf("%s", s[n] + 1);
		int len = strlen(s[n] + 1);
		for (int j = 1; j <= len; j++) {
			if (s[n][j] == 'E') {
				flag = j;
				break;
			}
		}
		if (flag > 0) break;
		n++;
	}
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			int len = strlen(s[i] + 1);
			for (int j = 1; j <= len; j++) {
				if (s[i][j] == 'W') a++;
				else b++;
				if ((a >= 11 || b >= 11) && abs(a - b) >= 2) {
					cout << a << ":" << b << endl;
					a = 0, b = 0;
				}
			}
		}
		if (i == n) {
			int len = flag - 1;
			for (int j = 1; j <= len; j++) {
				if (s[i][j] == 'W') a++;
				else b++;
				if ((a >= 11 || b >= 11) && abs(a - b) >= 2) {
					cout << a << ":" << b << endl;
					a = 0, b = 0;
				}
			}
			cout << a << ":" << b << endl;
		}

	}
	a = 0; b = 0;
	cout << endl;
	for (int i = 1; i <= n; i++) {
		if (i != n) {
			int len = strlen(s[i] + 1);
			for (int j = 1; j <= len; j++) {
				if (s[i][j] == 'W') a++;
				else b++;
				if ((a >= 21 || b >= 21) && abs(a - b) >= 2) {
					cout << a << ":" << b << endl;
					a = 0, b = 0;
				}
			}
		}
		if (i == n) {
			int len = flag - 1;
			for (int j = 1; j <= len; j++) {
				if (s[i][j] == 'W') a++;
				else b++;
				if ((a >= 21 || b >= 21) && abs(a - b) >= 2) {
					cout << a << ":" << b << endl;
					a = 0, b = 0;
				}
			}
			cout << a << ":" << b << endl;
		}

	}
	return 0;
}
