#include<bits/stdc++.h>
#define ll long long
#define maxn 100050
#define pi pair<int, int>
using namespace std;
inline ll getnum() {
	ll ans = 0; char c; ll flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
struct node {
	ll v, w;
	node(ll vv, ll ww) {
		v = vv;
		w = ww;
	}
};
vector<node> G[maxn];
void adde(ll a, ll b, ll w) {
	G[a].push_back(node(b, w));
	G[b].push_back(node(a, w));
}
ll n, m, s, t, l;
ll w[maxn];
ll dp[maxn];
ll maxw;
ll d[maxn], vis[maxn];
int dijkstra(int mid, int s) {
	priority_queue<pi, vector<pi>, greater<pi> > q;
	fill(d + 1, d + n + 1, 0x7fffffffffffffff);
	d[s] = 0;
	fill(vis + 1, vis + n + 1, false);
	q.push(make_pair(d[s], s));
	while (!q.empty()) {
		pi now = q.top(); q.pop();
		int x = now.second;
		if (vis[x]) continue;
		vis[x] = true;
		if (w[x] > mid) continue;
		for (int i = 0; i < G[x].size(); i++) {
			int v = G[x][i].v, wi = G[x][i].w;
			if (d[v] > d[x] + wi && w[v] <= mid && d[x] + wi <= l) {
				d[v] = d[x] + wi;
				q.push(make_pair(d[v], v));
			}
		}
	}
	if (d[t] > l) return 0;
	else return 1;
}
int main() {
	while (scanf("%lld%lld%lld%lld%lld", &n, &m, &s, &t, &l) != EOF) {
		maxw = 0;
		for (int i = 1; i <= n; i++) {
			w[i] = getnum();
			maxw = max(maxw, w[i]);
		}
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			ll a, b; ll wi;
			a = getnum(), b = getnum(), wi = getnum();
			adde(a, b, wi);
		}
		ll li = 0, r = maxw + 100, mid = -1;
		ll ans = 0x7fffffffffffffff;
		while (li <= r) {
			mid = (li + r) >> 1;
			if (dijkstra(mid, s)) {
				r = mid - 1;
				ans = min(ans, mid);
			}
			else li = mid + 1;
		}
		if (li > maxw) cout << "-1" << endl;
		else cout << ans << endl;
	}
	return 0;
}