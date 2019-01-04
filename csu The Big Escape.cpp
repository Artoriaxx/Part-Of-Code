#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
vector<int> G[maxn];
int sum;
void dfs(int u, int fa) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == fa) continue;
		sum++;
		dfs(v, u);
	}
}
int main() {
	int n, m;
	int cnt = 0;
	while (scanf("%d%d", &n, &m) != EOF) {
		cnt++;
		for (int i = 1; i <= 100000; i++) {
			G[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		int ans = 0;
		for (int i = 0; i < G[m].size(); i++) {
			int v = G[m][i];
			sum = 0;
			dfs(v, m);
			ans = max(ans, sum);
		}
		printf("Case #%d:%d\n", cnt, ans + 1);
	}
}