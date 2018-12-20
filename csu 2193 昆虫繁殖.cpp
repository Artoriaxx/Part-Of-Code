#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll getnum() {
	ll ans = 0; char c; ll flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
ll a[100], b[100];
int main() {
	ll x = getnum(), y = getnum(), z = getnum();
	a[1] = 1;
	for (int i = 1; i <= x; i++) {
		a[i] = 1;
		b[i] = 0;
	}
	for (int i = x + 1; i <= z + 1; i++) {
		if (i == 1) {
			a[i] = 1;
		}
		else a[i] = a[i - 1] + b[i - 2];
		b[i] = y * a[i - x];
	}
	if (x == z) {
		cout << "1";
	}
	else cout << a[z + 1];
	return 0;
}