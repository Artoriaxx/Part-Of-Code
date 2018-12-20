#include<bits/stdc++.h>
using namespace std;
inline int getnum() {
	char c; int ans = 0; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int n;
int a[200];
int f[300000];
int main() {
	int t;
	t = getnum();
	while (t--) {
		n = getnum();
		for (int i = 1; i <= n; i++) {
			a[i] = getnum();
		}
		memset(f, 0, sizeof(f));
		sort(a + 1, a + n + 1);
		int cnt = n;
		for (int i = 1; i <= n; i++) {
			if (f[a[i]] == 1) {
				cnt--;
				continue;
			}
			f[a[i]] = 1;
			for (int j = a[i]; j <= a[n]; j++) {
				f[j] = max(f[j], f[j - a[i]]);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}