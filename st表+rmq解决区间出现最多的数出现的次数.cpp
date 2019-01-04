#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

int a[maxn];
int value[maxn], cnt[maxn], num[maxn], L[maxn], R[maxn];
int st[maxn][20], lg2[maxn];
int n, q;
int k;

void ST() {
	for (int i = 1; i <= k; i++) {
		st[i][0] = cnt[i];
	}
	for (int j = 1; (1 << j) <= k; j++) {
		for (int i = 1; (i + (1 << j) - 1) <= k; i++) {
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	for (int i = 2; i <= k; i++) {
		lg2[i] = lg2[i >> 1] + 1;
	}
}

int rmq(int l, int r) {
	if (l>r)
		return 0;
	else {
		int x = lg2[r - l + 1];
		return max(st[l][x], st[r - (1 << x) + 1][x]);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	k = 0;
	value[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != value[k]) {
			R[k] = i;
			value[++k] = a[i];
			L[k] = i - 1;
			cnt[k] = 1;
			num[i] = k;
		}
		else {
			cnt[k]++;
			num[i] = num[i - 1];
		}
	}
	R[k] = n + 1;
	ST();
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (num[l] == num[r]) {
			printf("%d\n", r - l + 1);
		}
		else {
			int tmp = max(R[num[l]] - l, r - L[num[r]]);
			int ans = max(tmp, rmq(num[l] + 1, num[r] - 1));
			printf("%d\n", ans);
		}
	}
	return 0;
}
