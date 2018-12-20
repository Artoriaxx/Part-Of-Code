#include<bits/stdc++.h>
#define maxn 5050
using namespace std;

struct node {
	int v, w;
	node(int vv) {
		v = vv;
	}
};
vector<node> G[maxn], g[maxn];
void adde(int a, int b) {
	G[a].push_back(node(b));
	G[b].push_back(node(a));
}

inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}

int n, m;
int vis[maxn];
int cnt = 0;
int ans[maxn], tmp[maxn];
int del[maxn][maxn];

int cmp(node a, node b) {
	return a.v < b.v;
}

void dfs(int u, int f) {//假如n == m - 1，则直接贪心选取较小的边，对连向的点进行排序直接遍历图即可
	ans[++cnt] = u;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (v != f)
			dfs(v, u);
	}
}
int num;
int find(int u, int f) {//找环
	if (num) return 0;//假如已经找到了环的起点，则退出搜索，因为此时环已经构建好了
	vis[u] = 1;//已经遍历过这个点
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (v == f) continue;
		if (vis[v]) {//假如找到了遍历过的点，说明形成了环
			num = v;//环的起点为num
			g[u].push_back(node(v));//将构成环的这条边加入
			return 1;//返回1，代表可以找到环
		}
		if (find(v, u)) {//假如从v开始能找到环的话
			if (v == num) return 0;//如果连向的点就是起点，则返回，因为这条边不在环内
			g[u].push_back(node(v));//将在环内的边加入图g
			return 1;//返回可以找到环，这样就可以将一整个环内的边全部加入g
		}
	}
}
void dfs1(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	tmp[++cnt] = u;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (del[u][v] == 0) dfs1(v);
	}
}
int check() {
	for (int i = 1; i <= n; i++) {
		if (ans[i] == tmp[i]) continue;
		if (ans[i] > tmp[i]) return 1;
		else return 0;
	}
}

int main() {
	n = getnum(), m = getnum();
	for (int i = 1; i <= m; i++) {
		int a = getnum(), b = getnum();
		adde(a, b);
	}
	for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end(), cmp);//排序
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = n;//将ans赋值为最大值
	}
	if (n == m) {
		find(1, -1);
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < g[i].size(); j++) {
				memset(vis, 0, sizeof(vis));
				int v = g[i][j].v;
				del[i][v] = 1; del[v][i] = 1;
				cnt = 0;
				dfs1(1);
				del[i][v] = 0; del[v][i] = 0;
				if (check()) {
					for (int i = 1; i <= n; i++) {
						ans[i] = tmp[i];
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}
	dfs(1, -1);
	for (int i = 1; i <= cnt; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}