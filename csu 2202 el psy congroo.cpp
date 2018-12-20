#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
inline int getnum() {
	char c; int ans = 0; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
struct node {
	int l, r;
	bool operator < (const node a) const {
		return l < a.l;
	}
} a[maxn];
int main() {
	int t = getnum();
	while (t--) {
		priority_queue<int, vector<int>, greater<int> > q;
		int n = getnum(), k = getnum();
		for (int i = 1; i <= n; i++) {
			a[i].l = getnum();
			a[i].r = getnum();
		}
		sort(a + 1, a + n + 1);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (q.size() >= k) {
				q.pop();
			}
			q.push(a[i].r);
			if (q.size() == k) {
				int x = q.top();
				if (x - a[i].l > ans) {
					ans = x - a[i].l;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}