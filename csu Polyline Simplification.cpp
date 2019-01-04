#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
struct point {
	int x, y;
} a[maxn];
int l[maxn], r[maxn];
int area[maxn];
struct node {
	int val, id;
	node(int val = 0, int id = 0): val(val), id(id) {}
	bool operator < (const node &a) const {
		if (val == a.val) return id < a.id;
		else return val < a.val;
	}
};
int calc1(int x) {
	int p1 = l[x], p2 = x, p3 = r[x];
	return abs(a[p1].x * a[p2].y + a[p2].x * a[p3].y + a[p3].x * a[p1].y - a[p1].x * a[p3].y - a[p2].x * a[p1].y - a[p3].x * a[p2].y);
}
set<node> s;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int k = n - m;
	for (int i = 0; i <= n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	r[0] = 1;
	l[n] = n - 1;
	for (int i = 1; i < n; i++) {
		l[i] = i - 1; r[i] = i + 1;
		area[i] = calc1(i);
		s.insert(node(area[i], i));
	}
	for (int i = 1; i <= k; i++) {
		set<node>::iterator it = s.begin();
		int now = (*it).id;
		printf("%d\n", now);
		s.erase(it);
		l[r[now]] = l[now];
		r[l[now]] = r[now];
		if (l[now] > 0) {
			it = s.find(node(area[l[now]], l[now]));
			s.erase(it);
			area[l[now]] = calc1(l[now]);
			s.insert(node(area[l[now]], l[now]));
		}
		if (r[now] < n) {
			it = s.find(node(area[r[now]], r[now]));
			s.erase(it);
			area[r[now]] = calc1(r[now]);
			s.insert(node(area[r[now]], r[now]));
		}
	}
	return 0;
}