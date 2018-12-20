#include<bits/stdc++.h>
#define p 1000000007
typedef long long ll;
using namespace std;
inline ll fastPow(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return ans % p;
}
inline int count(int x) {
	int ans = 0;
	while (x) {
		if (x & 1) ans++;
		x >>= 1;
	}
	return ans;
}
int main() {
	int x, n;
	scanf("%d%d", &x, &n);
	ll base = fastPow(2, n) - 1;
	ll ans = 0;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			int num = count(i);
			ans = (ans + fastPow(base, num)) % p;
			if (i * i != x) {
				num = count(x / i);
				ans = (ans + fastPow(base, num)) % p;
			}
		}
	}
	cout << ans;
	return 0;
}