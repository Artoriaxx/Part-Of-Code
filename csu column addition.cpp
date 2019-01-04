#include<bits/stdc++.h>
using namespace std;
int a[1050], b[1050], ans[1050], f[1050];
int k[1050];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &b[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &ans[i]);
		}
		int ans1 = 0;
		memset(f, 0, sizeof(f));
		memset(k, 0, sizeof(k));
		for (int i = n; i >= 1; i--) {
			if ((a[i] + b[i]) % 10 == ans[i]) {
				f[i] = 1;
				if (a[i] + b[i] - 10 == ans[i]) k[i] = 1;
				else {
					k[i] = 0;
					ans1 = max(ans1, f[i]);
				}
			}
			for (int j = n; j > i; j--) {
				if ((a[i] + b[i] + k[j]) % 10 == ans[i]) {
					f[i] = max(f[i], f[j] + 1);
					if (a[i] + b[i] + k[j] - 10 == ans[i]) k[i] = 1;
					else {
						k[i] = 0;
						ans1 = max(ans1, f[i]);
					}
				}
			}
		}
		printf("%d\n", n - ans1);
	}
	return 0;
}