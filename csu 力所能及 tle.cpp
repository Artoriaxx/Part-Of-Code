#include<bits/stdc++.h>
#define maxn 10050
#define mid ((l + r) >> 1)
using namespace std;
inline int getnum() {
	char c; int ans = 0; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}

int L[maxn << 5], R[maxn << 5];//指向左子树和右子树的根
int sum[maxn << 5];//离散化去重后的每个节点所包含的数的个数
int cnt;//所有节点的计数器

int build(int l, int r) {//建一棵空树
	int rt = ++cnt;
	sum[rt] = 0;
	if (l < r) {
		L[rt] = build(l, mid);
		R[rt] = build(mid + 1, r);
	}
	return rt;
}

int update(int pre, int l, int r, int x) {
	int rt = ++cnt;
	L[rt] = L[pre], R[rt] = R[pre], sum[rt] = sum[pre] + 1;
	if (l < r) {
		if (x <= mid) L[rt] = update(L[pre], l, mid, x);
		else R[rt] = update(R[pre], mid + 1, r, x);
	}
	return rt;
}

int query(int u, int v, int l, int r, int k) {
	if (l >= r) return l;
	int x = sum[L[v]] - sum[L[u]];
	if (x >= k) return query(L[u], L[v], l, mid, k);
	else return query(R[u], R[v], mid + 1, r, k - x);
}

struct node {
	int x, v;
	bool operator < (const node a) const {
		return x < a.x;
	}
	node(int xx = 0, int vv = 0) {
		x = xx, v = vv;
	}
} task1[maxn];
int count1[maxn];
int a[maxn];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x = getnum(), v = getnum();
			if (v <= 0) continue;
			task1[++cnt] = node(x, v);
		}
		int m = getnum();
		sort(task1 + 1, task1 + cnt + 1);
		for (int i = 1; i <= m; i++) {
			int maxv = 0;
			memset(a, 0, sizeof(a));
			int l = getnum(), r = getnum(), k = getnum();
			l = lower_bound(task1 + 1, task1 + cnt + 1, node(l, 0)) - task1;
			if (task1[l].x > r) {
				printf("0\n");
				continue;
			}
			r = upper_bound(task1 + 1, task1 + cnt + 1, node(r, 0)) - task1 - 1;
			if (r > cnt) r = cnt;
			for (int i = l; i <= r; i++) {
				maxv = max(maxv, task1[i].v);
			}
			for (int i = 1; i <= maxv; i++) {
				count1[i] = 0;
			}
			for (int i = l; i <= r; i++) {
				count1[task1[i].v]++;
			}
			for (int i = 2; i <= maxv; i++) {
				count1[i] += count1[i - 1];
			}
			for (int i = r; i >= l; i--) {
				a[count1[task1[i].v]] = task1[i].v;
				count1[task1[i].v]--;
			}
			int cnt1 = 0; long long ans = 0;
			for (int i = r - l + 1; i >= 1; i--) {
				++cnt1;
				if (cnt1 <= k) {
					ans += a[i];
				}
				else break;
			}
			printf("%lld\n", ans);
		}
		printf("\n");
	}
	return 0;
}