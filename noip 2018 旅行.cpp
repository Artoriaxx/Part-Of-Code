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

void dfs(int u, int f) {//����n == m - 1����ֱ��̰��ѡȡ��С�ıߣ�������ĵ��������ֱ�ӱ���ͼ����
	ans[++cnt] = u;
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (v != f)
			dfs(v, u);
	}
}
int num;
int find(int u, int f) {//�һ�
	if (num) return 0;//�����Ѿ��ҵ��˻�����㣬���˳���������Ϊ��ʱ���Ѿ���������
	vis[u] = 1;//�Ѿ������������
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i].v;
		if (v == f) continue;
		if (vis[v]) {//�����ҵ��˱������ĵ㣬˵���γ��˻�
			num = v;//�������Ϊnum
			g[u].push_back(node(v));//�����ɻ��������߼���
			return 1;//����1����������ҵ���
		}
		if (find(v, u)) {//�����v��ʼ���ҵ����Ļ�
			if (v == num) return 0;//�������ĵ������㣬�򷵻أ���Ϊ�����߲��ڻ���
			g[u].push_back(node(v));//���ڻ��ڵı߼���ͼg
			return 1;//���ؿ����ҵ����������Ϳ��Խ�һ�������ڵı�ȫ������g
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
		sort(G[i].begin(), G[i].end(), cmp);//����
	}
	for (int i = 1; i <= n; i++) {
		ans[i] = n;//��ans��ֵΪ���ֵ
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