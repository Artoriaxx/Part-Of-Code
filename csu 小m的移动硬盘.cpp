#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
struct node {
	int l, r;
} a[maxn];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			a[i].l = i - 1;
			a[i].r = i + 1;
		}
		a[0].r = 1;
		a[n + 1].l = n;
		for (int i = 1; i <= m; i++) {
			int q;
			scanf("%d", &q);
			if (q == 1) {
				int x;
				scanf("%d", &x);
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[x].l = 0;
				a[x].r = a[0].r;
				a[a[0].r].l = x;
				a[0].r = x;
			}
			if (q == 2) {
				int x;
				scanf("%d", &x);
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[x].r = n + 1;
				a[x].l = a[n + 1].l;
				a[a[n + 1].l].r = x;
				a[n + 1].l = x;
			}
			if (q == 3) {
				int x, y;
				scanf("%d%d", &x, &y);
				if (x == y) continue;
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[x].r = a[y].r;
				a[a[y].r].l = x;
				a[x].l = y;
				a[y].r = x;
			}
		}
		int now = a[0].r;
		for (int i = 1; i < n; i++) {
			printf("%d ", now);
			now = a[now].r;
		}
		printf("%d\n", now);
	}
	return 0;
}