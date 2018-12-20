#include <bits/stdc++.h>
#define maxn 100000050
using namespace std;
int cnt, notprime[maxn], prime[maxn];
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int main() {
	int n = getnum();
	for (int i = 2; i <= n; i++) {
		if (!notprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && i * prime[j] <= 300; j++) {
			notprime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		printf("%d ", prime[i]);
	}
	return 0;
}