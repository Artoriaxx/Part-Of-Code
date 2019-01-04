#include<bits/stdc++.h>
#define maxn 250
using namespace std;
long long w[maxn];
int a[maxn];
long long f[maxn][maxn];
long long pre[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &w[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = 0x7fffffffffffffff;
			}
		}
		for (int i = 1; i <= n; i++) {
			pre[i] = pre[i - 1] + w[a[i]];
			f[i][i] = w[a[i]];
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 1; i <= n - len + 1; i++) {
				int l = i, r = i + len - 1;
				f[l][r] = min(f[l + 1][r], f[l][r - 1]) + pre[r] - pre[l - 1];
				for (int k = l + 1; k <= r - 1; k++) {
					f[l][r] = min(f[l][k - 1] + f[k + 1][r] + pre[r] - pre[l - 1], f[l][r]);
				}
			}
		}
		cout << f[1][n] << endl;
	}
}