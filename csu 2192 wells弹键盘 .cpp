#include<bits/stdc++.h>
using namespace std;
char s[105];
int f[105][15][15];
int a[105];
int main() {
	while (scanf("%s", s + 1) != EOF) {
		int n = strlen(s + 1);
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= 10; j++) {
				for (int k = 1; k <= 10; k++) {
					f[i][j][k] = 0x3f3f3f3f;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (s[i] == '0') a[i] = 10;
			else a[i] = s[i] - '0';
		}
		f[0][5][6] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < a[i]; j++) {
				for (int l = 1; l <= 10; l++) {
					for (int r = l + 1; r <= 10; r++) {
						int s = abs(r - a[i]) + 1;
						if (abs(l - j) > s) continue;
						f[i][j][a[i]] = min(f[i][j][a[i]], f[i - 1][l][r] + s);
						
					}
				}
			}
			for (int k = a[i] + 1; k <= 10; k++) {
				for (int l = 1; l <= 10; l++) {
					for (int r = l + 1; r <= 10; r++) {
						int s = abs(l - a[i]) + 1;
						if (abs(r - k) > s) continue;
						f[i][a[i]][k] = min(f[i][a[i]][k], f[i - 1][l][r] + s);
					}
				}
			}
		}
		int ans = 0x3f3f3f3f;
		for (int i = 1; i <= 10; i++) {
			if (a[n] < i)
				ans = min(f[n][a[n]][i], ans);
		}
		for (int i = 1; i <= 10; i++) {
			if (i < a[n])
				ans = min(f[n][i][a[n]], ans);
		}
		cout << ans << endl;
	}
	return 0;
}
