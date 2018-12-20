#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll getnum() {
	ll ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int main() {
	ll n = getnum(), m = getnum();
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ll x = getnum();
		ans ^= x;
	}
	cout << ans;
	return 0;
}