#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll f[50][50];
int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		n++;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				f[i][j] = 0;
			}
		}
		f[1][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
		cout << f[n][n] << endl;
	}
	return 0;
}