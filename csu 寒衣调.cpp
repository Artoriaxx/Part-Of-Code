#include<bits/stdc++.h>
#define ll long long
#define maxn 100050
using namespace std;
ll n, p;
ll a[maxn];
ll pre[maxn], last[maxn];
int main() {
	while (scanf("%lld%lld", &n, &p) != EOF) {
		pre[0] = last[n + 1] = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			pre[i] = (pre[i - 1] % p * a[i] % p) % p;
		}
		for (int i = n; i >= 1; i--) {
			last[i] = (last[i + 1] % p * a[i] % p) % p;
		}
		for (int i = 1; i <= n; i++) {
			a[i] == 0 ? printf("1 ") : printf("%lld ", (pre[i - 1] % p * last[i + 1] % p) % p);
		}
	}
	return 0;
}
