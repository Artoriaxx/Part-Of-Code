#include<bits/stdc++.h>
#include<set>
#define ll long long
#define maxn 1000050
using namespace std;
ll a[maxn];
inline ll getnum() {
	char c; ll ans = 0; ll flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int main() {
	ll n, k;
	multiset<ll> s;
	while (scanf("%lld%lld", &n, &k) != EOF) {
		s.clear();
		for (int i = 1; i <= n; i++) {
			a[i] = getnum();
		}
		int l = 1, r = 1;
		int ans = 0;
		s.insert(a[r]);
		while (r <= n) {
			ll now = *(--s.end()) - *(s.begin());
			if (now > k) {
				multiset<ll>::iterator it;
				it = s.find(a[l]); l++;
				s.erase(it);
			}
			else {
				ans = max(r - l + 1, ans);
				if (r + 1 <= n) s.insert(a[++r]);
				else break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}