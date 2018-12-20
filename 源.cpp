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
		int head = 1, tail = n;
		for (int i = 1; i <= m; i++) {
			int q;
			scanf("%d", &q);
			if (q == 1) {
				int x;
				scanf("%d", &x);
				if (x == head) continue;
				if (x == tail) tail = a[x].l;
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[head].l = x;
				a[x].l = 0;
				a[x].r = head;
				head = x;
			}
			if (q == 2) {
				int x;
				scanf("%d", &x);
				if (x == tail) continue;
				if (x == head) head = a[x].r;
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[tail].r = x;
				a[x].l = tail;
				a[x].r = n + 1;
				tail = x;
			}
			if (q == 3) {
				int x, y;
				scanf("%d%d", &x, &y);
				if (x == y) continue;
				if (x == head) {
					head = a[x].r;
				}
				if (y == tail) {
					tail = x;
				}
				a[a[x].l].r = a[x].r;
				a[a[x].r].l = a[x].l;
				a[x].r = a[y].r;
				a[a[y].r].l = x;
				a[x].l = y;
				a[y].r = x;
			}
		}
		int now = head;
		for (int i = 1; i < n; i++) {
			printf("%d ", now);
			now = a[now].r;
		}
		printf("%d\n", now);
	}
	return 0;
}