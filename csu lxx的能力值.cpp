#include<bits/stdc++.h>
#define maxn 1050
using namespace std;
typedef long long ll;
ll a[maxn * 2];
bool check(ll x, int n, int m, int l) {
	for (int pos = 1; pos <= n; pos++) {
		int i;
		int tmp = m;
		for (i = pos; i <= pos + n - 1; i++) {
			if (a[i] < x) {
				if (tmp > 0) {
					tmp--;
					i += l - 1;
				}
				else break;
			}
		}
		if (i > pos + n - 1) return true;
	}
	return false;
}
int main() {
	int n, m, li;
	while (scanf("%d%d%d", &n, &m, &li) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			a[i + n] = a[i];
		}
		ll l = 0, r = 1000000000 + 100;
		ll ans = 0;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid, n, m, li)) {
				l = mid + 1;
				ans = max(ans, mid);
			}
			else r = mid - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}