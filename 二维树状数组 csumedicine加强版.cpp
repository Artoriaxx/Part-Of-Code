#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int n, m;
int d[maxn][maxn][30];
inline int lowbit(int x) {
	return x & (-x);
}
inline void update(int x, int y, int z, int v) {
	for (int i = x; i <= n; i += lowbit(i)) {
		for (int j = y; j <= m; j += lowbit(j)) {
			d[i][j][z] += v;
		}
	}
}
inline int sumv(int x, int y, int z) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		for (int j = y; j; j -= lowbit(j)) {
			ans += d[i][j][z];
		}
	}
	return ans;
}
inline int query(int x1, int y11, int x2, int y2, int z) {
	return sumv(x2, y2, z) - sumv(x1 - 1, y2, z) - sumv(x2, y11 - 1, z) + sumv(x1 - 1, y11 - 1, z);
}
char mat[maxn][maxn];
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 1; k <= 26; k++) {
					d[i][j][k] = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%s", mat[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				update(i, j, mat[i][j] - '0' - 48, 1);
			}
		}
		int x = getnum();
		while (x--) {
			int q = getnum();
			if (q == 1) {
				int x1 = getnum(), y11 = getnum(), x2 = getnum(), y2 = getnum();
				for (int i = 1; i <= 26; i++) {
					int ans = query(x1, y11, x2, y2, i);
					if (i != 26) printf("%d ", ans);
					else printf("%d\n", ans);
				}
			}
			if (q == 0) {
				int x = getnum(), y = getnum();
				char ch[2];
				scanf("%s", ch);
				update(x, y, ch[0] - '0' - 48, 1);
				update(x, y, mat[x][y] - '0' - 48, -1);
				mat[x][y] = ch[0];
			}
		}
	}
	return 0;
}