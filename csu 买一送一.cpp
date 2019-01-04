#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
vector<int> G[maxn];
int a[maxn];
long long f[maxn];
int vis[maxn];
long long pre[maxn];
void dfs(int u, int fa, int cnt) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (!vis[a[u]]) cnt++;
		vis[a[u]]++;
		f[v] = f[u] + cnt - pre[a[v]];
		int tmp = pre[a[v]];
		pre[a[v]] = cnt;
		dfs(v, u, cnt);
		vis[a[u]]--;
		if (vis[a[u]] == 0) cnt--;
		pre[a[v]] = tmp;
	}
}
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(f, 0, sizeof(f));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int x;
			scanf("%d", &x);
			G[x].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) continue;
		dfs(1, 0, 0);
		for (int i = 2; i <= n; i++) {
			printf("%lld\n", f[i]);
		}
	}
	return 0;
}