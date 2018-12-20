#include<bits/stdc++.h>
#define maxn 10050
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int a[maxn], b[maxn], g[maxn], k[maxn];
int main() {
	int n = getnum();
	bool flag = 0;
	for (int i = 1; i <= n + 1; i++) {
		int x = getnum();
		if (x == 0) continue;
		else if (x == 1) {
			if (i != n + 1 && flag) {
				if (n - i + 1 == 1) {
					cout << "+x";
				}
				else cout << "+x^" << n - i + 1;
			}
			if (i == n + 1 && flag) {
				cout << "+1";
			}
			if (!flag && i == n + 1) {
				cout << "1";
			}
			if (!flag && i != n + 1) {
				if (n - i + 1 == 1) cout << "x";
				else cout << "x^" << n - i + 1;
				flag = 1;
			}
		}
		else if (x == -1) {
			if (i != n + 1) {
				if (n - i + 1 == 1) {
					cout << "-x";
				}
				else cout << "-x^" << n - i + 1;
				flag = 1;
			}
			if (i == n + 1) {
				cout << "-1";
			}
		}
		else {
			if (!flag) {
				if (n - i + 1 == 1) cout << x << "x";
				cout << x << "x^" << n - i + 1;
				flag = 1;
			}
			else if (i == n + 1) {
				if (x > 0)
					cout << "+" << x;
				else cout << x;
			}
			else {
				if (x > 0) {
					if (n - i + 1 == 1) {
						cout << "+" << x << "x";
					}
					else cout << "+" << x << "x^" << n - i + 1;
				}
				else {
					if (n - i + 1 == 1) {
						cout << x << "x";
					}
					else cout << x << "x^" << n - i + 1;
				}
			}
		}
	}
	return 0;
}