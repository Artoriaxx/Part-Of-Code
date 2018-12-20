#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
const long long p = 1e9 + 7;
long long fac[maxn];
long long fast_pow(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans % p;
}
long long C(int m, int n) {
	return fac[n] * fast_pow(fac[m], p - 2) % p * fast_pow(fac[n - m], p - 2) % p;
}
int main() {
	int t;
	scanf("%d", &t);
	fac[0] = 1;
	for (int i = 1; i <= maxn; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		if (m > n) swap(n, m);
		printf("%d\n", C(m, n));
	}
}