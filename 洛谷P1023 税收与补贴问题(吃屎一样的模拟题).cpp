#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
int a[maxn];
int x[maxn], y[maxn];
int cmp(int x, int y) {
	return x > y;
}
int main() {
	int exp1;
	scanf("%d", &exp1);
	scanf("%d%d", &x[1], &y[1]);
	a[x[1]] = y[1];
	int maxx = 0;
	int n = 2;
	int a1, b;
	while (scanf("%d%d", &a1, &b)) {
		if (a1 == -1 && b == -1) break;
		x[n] = a1; y[n] = b;
		n++;
	}
	sort(x + 1, x + n);
	sort(y + 1, y + n, cmp);
	for (int i = 2; i <= n; i++) {
		for (int j = x[i - 1] + 1; j <= x[i]; j++) {
			a[j] = a[j - 1] - (y[i - 1] - y[i]) / (x[i] - x[i - 1]);
		}
	}
	int change;
	scanf("%d", &change);
	int l, m, r;
	if (exp1 >= x[n - 1]) {
		m = y[n - 1] - (exp1 - x[n - 1]) * change;
		l = y[n - 1] - (exp1 - x[n - 1] - 1) * change;
		r = y[n - 1] - (exp1 - x[n - 1] + 1) * change;
	}
	else {
		m = a[exp1];
		l = a[exp1 - 1];
		r = a[exp1 + 1];
	}
	int ans = maxn;
	for (int i = 0; i <= maxn; i++) {
		int ansl = (exp1 - 1 - x[1] + i) * l;
		int ansm = (exp1 - x[1] + i) * m;
		int ansr = (exp1 - x[1] + i + 1) * r;
		if (ansm >= ansl && ansm >= ansr) {
			ans = i;
			break;
		}
	}
	for (int i = 0; i >= -maxn; i--) {
		int ansl = (exp1 - 1 - x[1] + i) * l;
		int ansm = (exp1 - x[1] + i) * m;
		int ansr = (exp1 - x[1] + i + 1) * r;
		if (ansm >= ansl && ansm >= ansr) {
			if (abs(i) < ans) {
				ans = i;
			}
			break;
		}
	}
	cout << ans;
	return 0;
}
