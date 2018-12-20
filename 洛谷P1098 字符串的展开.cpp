#include<bits/stdc++.h>
using namespace std;
char s[150];
int main() {
	int p1, p2, p3;
	scanf("%d%d%d", &p1, &p2, &p3);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		if (s[i] == '-') {
			if (i == 1) {
				cout << '-';
				continue;
			}
			if (s[i + 1] - s[i - 1] == 1) {
				continue;
			}
			else if (s[i + 1] - s[i - 1] <= 0) {
				cout << '-';
				continue;
			}
			else if (!((s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z') || (isdigit(s[i + 1]) && isdigit(s[i - 1])))) {
				cout << '-';
				continue;
			}
			else {
				if (p1 == 1) {
					int x = s[i + 1] - s[i - 1] - 1;
					if (p3 == 1) {
						if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
							for (int j = 1; j <= x; j++) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + j;
									cout << c;
								}
							}
						}
						else {
							for (int j = 1; j <= x; j++) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + j;
									cout << c;
								}
							}
						}
					}
					else {
						if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
							for (int j = x; j >= 1; j--) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + j;
									cout << c;
								}
							}
						}
						else {
							for (int j = x; j >= i; j--) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + 1;
									cout << c;
								}
							}
						}
					}
				}
				else if (p1 == 2) {
					int x = s[i + 1] - s[i - 1] - 1;
					if (p3 == 1) {
						if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
							for (int j = 1; j <= x; j++) {
								for (int k = 1; k <= p2; k++) {
									char  c = 'A' + s[i - 1] - 'a' + j;
									cout << c;
								}
							}
						}
						else {
							for (int j = 1; j <= x; j++) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + j;
									cout << c;
								}
							}
						}
					}
					else {
						if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
							for (int j = x; j >= 1; j--) {
								for (int k = 1; k <= p2; k++) {
									char c = 'A' + s[i - 1] - 'a' + j;
									cout << c;
								}
							}
						}
						else {
							for (int j = x; j >= 1; j--) {
								for (int k = 1; k <= p2; k++) {
									char c = s[i - 1] + j;
									cout << c;
								}
							}
						}
					}
				}
				else if (p1 == 3) {
					int x = s[i + 1] - s[i - 1] - 1;
					for (int j = 1; j <= x; j++) {
						for (int k = 1; k <= p2; k++) {
							cout << "*";
						}
					}
				}
			}
		}
		else cout << s[i];
	}
	return 0;
}