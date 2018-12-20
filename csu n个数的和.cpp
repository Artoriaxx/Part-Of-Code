#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			printf("0\n");
			continue;
		}
		ll a1, b1;
		ll a2, b2;
		scanf("%lld/%lld", &a1, &b1);
		ll tmp = gcd(a1, b1);
		a1 /= tmp; b1 /= tmp;
		for (int i = 2; i <= n; i++) {
			scanf("%lld/%lld", &a2, &b2);
			ll tmp = gcd(a2, b2);
			a2 /= tmp; b2 /= tmp;
			ll c = gcd(b1, b2);
			ll d = b1 / c * b2;
			ll e = d / b1 * a1;
			ll f = d / b2 * a2;
			b1 = d;
			a1 = e + f;
			if (a1 != 0) {
				ll g = gcd(a1, b1);
				a1 /= g; b1 /= g;
			}
			if (b1 < 0) {
				a1 = -a1;
				b1 = -b1;
			}
		}
		bool flag = false;
		if (a1 < 0) {
			printf("-");
			flag = true;
			a1 = -a1;
		}
		if (a1 == 0) {
			printf("0\n");
		}
		else if (a1 < b1) {
			printf("%lld/%lld\n", a1, b1);
		}
		else {
			if (b1 == 1) {
				printf("%lld\n", a1);
			}
			else {
				ll c = a1 / b1;
				printf("%lld ", c);
				a1 -= b1 * c;
				if (!flag)
					printf("%lld/%lld\n", a1, b1);
				else {
					printf("-%lld/%lld\n", a1, b1);
				}
			}
		}
	}
	return 0;
}