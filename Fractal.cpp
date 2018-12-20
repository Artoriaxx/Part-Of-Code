#include<bits/stdc++.h>
using namespace std;
struct node {
	int x;
	string a[250];
	node() { x = 0; for (int i = 0; i<250; i++) a[i] = ""; }
};
int sss;
char a1, b1, c1, d1, e1, f1, g1, h1, i1;
node M(node a, int k) {
	if (k == 0) return a;
	node ans;
	ans.x = a.x*sss;
	for (int i = 0; i < a.x; i++)
		for (int j = 0; j < a.x; j++)
		{
			if (sss == 2)
			{
				if (a.a[i][j] == '*')
				{
					ans.a[i * 2] += '*'; ans.a[i * 2] += '*';
					ans.a[i * 2 + 1] += '*'; ans.a[i * 2 + 1] += '*';
				}
				else
				{
					ans.a[i * 2] += a1; ans.a[i * 2] += b1;
					ans.a[i * 2 + 1] += c1; ans.a[i * 2 + 1] += d1;
				}
			}
			else if (sss == 3)
			{
				if (a.a[i][j] == '*')
				{
					ans.a[i * 3] += '*'; ans.a[i * 3] += '*'; ans.a[i * 3] += '*';
					ans.a[i * 3 + 1] += '*'; ans.a[i * 3 + 1] += '*'; ans.a[i * 3 + 1] += '*';
					ans.a[i * 3 + 2] += '*'; ans.a[i * 3 + 2] += '*'; ans.a[i * 3 + 2] += '*';
				}
				else
				{
					ans.a[i * 3] += a1; ans.a[i * 3] += b1; ans.a[i * 3] += c1;
					ans.a[i * 3 + 1] += d1; ans.a[i * 3 + 1] += e1; ans.a[i * 3 + 1] += f1;
					ans.a[i * 3 + 2] += g1; ans.a[i * 3 + 2] += h1; ans.a[i * 3 + 2] += i1;
				}
			}
		}
	return M(ans, k - 1);
}
int main() {
	node n;
	int k;
	scanf("%d%d", &n.x, &k);
	sss = n.x;
	for (int i = 0; i<n.x; i++)
		cin >> n.a[i];
	if (n.x == 2) {
		a1 = n.a[0][0];
		b1 = n.a[0][1];
		c1 = n.a[1][0];
		d1 = n.a[1][1];
	}
	if (n.x == 3) {
		a1 = n.a[0][0];
		b1 = n.a[0][1];
		c1 = n.a[0][2];
		d1 = n.a[1][0];
		e1 = n.a[1][1];
		f1 = n.a[1][2];
		g1 = n.a[2][0];
		h1 = n.a[2][1];
		i1 = n.a[2][2];
	}
	node ans;
	ans = M(n, k - 1);
	for (int i = 0; i<ans.x; i++)
		cout << ans.a[i] << '\n';
}
