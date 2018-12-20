#include<bits/stdc++.h>
#define maxn 500050
#define p 1000000007
using namespace std;
typedef long long ll;
ll a[maxn], b[maxn];
ll pre[maxn * 2];
int main() {
	int n, m, l, r;
	while (scanf("%d%d%d%d", &n, &m, &l, &r) != EOF) {
		for (int i = 1; i <= n + 1; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i = 1; i <= m + 1; i++) {
			scanf("%lld", &b[i]);
			pre[i] = (pre[i - 1] + b[i]) % p;
		}
		for (int i = m + 2; i <= r + 1; i++) {
			pre[i] = pre[i - 1];
		}
		ll ans = 0;
		for (int i = 1; i <= n + 1; i++) {
			ans = (ans + a[i] * (pre[r + 1] - pre[l] + p) % p) % p;
			if (l > 0) l--;
			if (r >= 0) r--;
		}
		printf("%lld\n", (ans + p) % p);
	}
	return 0;
}