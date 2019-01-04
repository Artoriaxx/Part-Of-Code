#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll d;
	scanf("%lld", &d);
	ll now = 100;
	ll limit = 100000;
	ll pre = 550;
	ll own = 0;
	ll price = 0;
	ll share = 0;
	for (int i = 1; i <= d; i++) {
		ll p;
		scanf("%lld", &p);
		if (own == 0) {
			if (now >= p) {
				share = (now / p <= limit ? now / p : limit);
				now -= share * p;
				own = share;
				price = p;
			}
		}
		else {
			if (p < pre) {
				now += pre * own;
				share = (now / p <= limit ? now / p : limit);
				now -= share * p;
				own = share;
				price = p;
			}
			if (i == d) {
				if (p < price) {
					now += share * price;
				}
				else {
					now += p * own;
				}
			}
		}
		pre = p;
	}
	if (d == 1) printf("100\n");
	else printf("%lld\n", now);
	return 0;
}