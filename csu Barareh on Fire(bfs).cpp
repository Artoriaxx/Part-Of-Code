#include<bits/stdc++.h>
#define maxn 150
using namespace std;
const int inf = 1e9;
int n, m, k;
char G[maxn][maxn];
int d[maxn][maxn];
int fire[maxn][maxn];

struct point {
	int x, y;
	point(int x = 0, int y = 0): x(x), y(y) {}
} s, t;
queue<point> q;
void init() {
	int dx[9] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int dy[9] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	while (!q.empty()) {
		point now = q.front(); q.pop();
		for (int i = 0; i < 8; i++) {
			point next = point(now.x + dx[i], now.y + dy[i]);
			if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m) {
				if (fire[next.x][next.y] > fire[now.x][now.y] + k) {
					fire[next.x][next.y] = fire[now.x][now.y] + k;
					q.push(next);
				}
			}
		}
	}
}
void bfs() {
	q.push(s);
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { -1, 1, 0, 0 };
	while (!q.empty()) {
		point now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			point next = point(now.x + dx[i], now.y + dy[i]);
			if (next.x > 0 && next.x <= n && next.y > 0 && next.y <= m) {
				if (d[now.x][now.y] + 1 >= fire[next.x][next.y]) continue;
				if (d[now.x][now.y] + 1 < d[next.x][next.y]) {
					d[next.x][next.y] = d[now.x][now.y] + 1;
					q.push(next);
				}
			}
		}
	}
}
int main() {
	while (scanf("%d%d%d", &n, &m, &k) != EOF) {
		if (n == 0 && m == 0 && k == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%s", G[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			fill(d[i] + 1, d[i] + m + 1, inf);
			fill(fire[i] + 1, fire[i] + m + 1, inf);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (G[i][j] == 's') {
					s.x = i; s.y = j;
					d[i][j] = 0;
				}
				if (G[i][j] == 't') {
					t.x = i; t.y = j;
				}
				if (G[i][j] == 'f') {
					fire[i][j] = 0;
					q.push(point(i, j));
				}
			}
		}
		init();
		bfs();
		if (d[t.x][t.y] == inf) printf("Impossible\n");
		else printf("%d\n", d[t.x][t.y]);
	}
	return 0;
}