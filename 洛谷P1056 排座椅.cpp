#include<bits/stdc++.h>
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
struct node {
	int v, pos;
} row[1050], column[1050];
bool cmp(node a, node b) {
	return a.v > b.v;
}
int ans1[1050], ans2[1050];
int main() {
	int n, m, k, l, d;
	m = getnum(), n = getnum(), k = getnum(), l = getnum(), d = getnum();
	for (int i = 1; i <= d; i++) {
		int x1 = getnum(), y11 = getnum(), x2 = getnum(), y2 = getnum();
		if (x1 == x2) {
			int tmp = min(y11, y2);
			column[tmp].v++;
			column[tmp].pos = tmp;
		}
		else {
			int tmp = min(x1, x2);
			row[tmp].v++;
			row[tmp].pos = tmp;
		}
	}
	sort(row, row + 1001, cmp);
	sort(column, column + 1001, cmp);
	for (int i = 1; i <= k; i++) {
		ans1[i] = row[i - 1].pos;
	}
	for (int i = 1; i <= l; i++) {
		ans2[i] = column[i - 1].pos;
	}
	sort(ans1 + 1, ans1 + k + 1);
	sort(ans2 + 1, ans2 + l + 1);
	for (int i = 1; i <= k; i++) {
		if (i != k) {
			cout << ans1[i] << " ";
		}
		else cout << ans1[i];
	}
	cout << '\n';
	for (int i = 1; i <= l; i++) {
		if (i != l) {
			cout << ans2[i] << " ";
		}
		else cout << ans2[i];
	}
	return 0;
}