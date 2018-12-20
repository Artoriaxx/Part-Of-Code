#include<bits/stdc++.h>
#define maxn 200050
#define mid ((l + r) >> 1)
using namespace std;

int a[maxn], b[maxn], T[maxn];

inline int getnum() {
	char c; int ans = 0; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}

int L[maxn << 5], R[maxn << 5];//ָ�����������������ĸ�
int sum[maxn << 5];//��ɢ��ȥ�غ��ÿ���ڵ������������ĸ���
int cnt;//���нڵ�ļ�����

int build(int l, int r) {//��һ�ÿ���
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
	if (l >= r) {
		if (l != k)
			return sum[v] - sum[u];
		else return 0;
	}
	int ans = sum[L[v]] - sum[L[u]];
	if (mid >= k) return query(L[u], L[v], l, mid, k);
	else return ans + query(R[u], R[v], mid + 1, r, k);
}

int main() {
	int t = getnum();
	while (t--) {
		int n = getnum(), q = getnum();
		cnt = 0;
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		memset(sum, 0, sizeof(sum));
		memset(T, 0, sizeof(T));
		for (int i = 1; i <= n; i++) {
			a[i] = getnum();
			b[i] = a[i];
		}
		sort(b + 1, b + n + 1);
		int m = unique(b + 1, b + n + 1) - b - 1;
		T[0] = build(1, m);
		for (int i = 1; i <= n; i++) {
			a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
			T[i] = update(T[i - 1], 1, m, a[i]);
		}
		while (q--) {
			int x = getnum(), y = getnum(), z = getnum();
			z = lower_bound(b + 1, b + m + 1, z) - b;
			printf("%d\n", query(T[x - 1], T[y], 1, m, z));
		}
	}
	return 0;
}