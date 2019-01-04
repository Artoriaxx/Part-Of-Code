#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;
char s[300];
double u, ii, p;
int main() {
	char n[4];
	scanf("%[^\n]%*c", n);
	int x = n[0] - '0';
	for (int i = 1; i <= x; i++) {
		scanf("%[^\n]%*c", s + 1);
		int len = strlen(s + 1);
		u = 0; ii = 0; p = 0;
		for (int i = 1; i <= len; i++) {
			if (s[i] == '=') {
				if (s[i - 1] == 'U') {
					int j = i + 1;
					bool flag = false;
					double tmp = 0.1;
					while (s[j] != 'V') {
						if (isdigit(s[j])) {
							if (!flag) {
								u = u * 10 + s[j] - '0';
							}
							else {
								u = u + (s[j] - '0') * tmp;
								tmp *= 0.1;
							}
						}
						else if (s[j] == '.') flag = true;
						else if (s[j] == 'm') u /= 1000;
						else if (s[j] == 'k') u *= 1000;
						else if (s[j] == 'M') u *= 1000000;
						j++;
					}
				}
				if (s[i - 1] == 'P') {
					int j = i + 1;
					bool flag = false;
					double tmp = 0.1;
					while (s[j] != 'W') {
						if (isdigit(s[j])) {
							if (!flag) {
								p = p * 10 + s[j] - '0';
							}
							else {
								p = p + (s[j] - '0') * tmp;
								tmp *= 0.1;
							}
						}
						else if (s[j] == '.') flag = true;
						else if (s[j] == 'm') p /= 1000;
						else if (s[j] == 'k') p *= 1000;
						else if (s[j] == 'M') p *= 1000000;
						j++;
					}
				}
				if (s[i - 1] == 'I') {
					int j = i + 1;
					bool flag = false;
					double tmp = 0.1;
					while (s[j] != 'A') {
						if (isdigit(s[j])) {
							if (!flag) {
								ii = ii * 10 + s[j] - '0';
							}
							else {
								ii = ii + (s[j] - '0') * tmp;
								tmp *= 0.1;
							}
						}
						else if (s[j] == '.') flag = true;
						else if (s[j] == 'm') ii /= 1000;
						else if (s[j] == 'k') ii *= 1000;
						else if (s[j] == 'M') ii *= 1000000;
						j++;
					}
				}
			}
		}
		if (u < eps) {
			cout << "U=";
			printf("%.2lf", p / ii);
			cout << "V";
			cout << endl;
		}
		else if (ii < eps) {
			cout << "I=";
			printf("%.2lf", p / u);
			cout << "A";
			cout << endl;
		}
		else if (p < eps) {
			cout << "P=";
			printf("%.2lf", ii * u);
			cout << "W";
			cout << endl;
		}
	}
	return 0;
}