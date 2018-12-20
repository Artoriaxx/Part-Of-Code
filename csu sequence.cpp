#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
long long a[maxn];
long long fast_pow(int a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
int main() {
	int n = getnum();
	long long maxx = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = getnum();
		maxx = max(a[i], maxx);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = int(log2(maxx / a[i]));
		if (a[i] * fast_pow(2, tmp) < maxx) tmp++;
		ans += tmp;
	}
	printf("%lld", ans + maxx);
	return 0;
}