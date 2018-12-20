#include<bits/stdc++.h>
#define maxn 150
#define pi pair<double, int>
using namespace std;
double d[maxn];
int n;
double k, x, y;
bool vis[maxn];
double dis(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
struct node {
	double x, y, r;
} a[maxn];
struct can {
	double c, d;
} can[maxn];
void dijkstra() {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	fill(d + 1, d + n + 1, 0x7fffffff);
	d[0] = 0.0;
	fill(vis, vis + n + 1, false);
	q.push(make_pair(d[0], 0));
	while (!q.empty()) {
		pi now = q.top(); q.pop();
		int x = now.second;
		if (vis[x]) continue;
		vis[x] = true;
		for (int i = 1; i <= n; i++) {
			int v = i;
			double dd = max(dis(a[x].x, a[x].y, a[i].x, a[i].y) - a[i].r - a[x].r, 0.0);
			if (x != i && dd <= k) {
				if (d[i] > d[x] + dd) {
					d[i] = d[x] + dd;
					q.push(make_pair(d[i], i));
				}
			}
		}
	}
}

int main() {
	
	while (scanf("%d%lf%lf%lf", &n, &k, &x, &y) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].r);
		}
		a[0].x = a[0].y = a[0].r = 0;
		dijkstra();
		double min1 = 0x7fffffff;
		int point = n + 1;
		a[point].x = x; a[point].y = y; a[point].r = 0;
		for (int i = 0; i <= n; i++) {
			if (dis(a[i].x, a[i].y, x, y) - a[i].r <= 0 && d[i] < min1) {
				point = i;
				min1 = d[i];
			}
		}
		double ans = 0x7fffffff;
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			double dd = max(dis(a[i].x, a[i].y, a[point].x, a[point].y) - a[i].r - a[point].r, 0.0);
			if (dd <= k) {
				can[++cnt].c = dd;
				can[cnt].d = d[i] + dd;
			}
		}
		for (int i = 1; i <= cnt; i++) {
			for (int j = 1; j <= cnt; j++) {
				if (can[i].c + can[j].c <= k) {
					ans = min(ans, can[i].d + can[j].d);
				}
			}
		}
		if (ans != 0x7fffffff) printf("%.10lf\n", ans);
		else printf("-1\n");
	}
	return 0;
}