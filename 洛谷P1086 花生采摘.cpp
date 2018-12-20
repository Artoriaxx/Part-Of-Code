#include<bits/stdc++.h>
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int a[25][25];
int main() {
	int n = getnum(), m = getnum(), k = getnum();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = getnum();
			if (a[i][j] > 0) cnt++;
		}
	}
	int oldx = 0, oldy;
	int newx, newy;
	int ans = 0;
	for (int i = 1; i <= cnt; ‘i++) {
		int max1 = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (a[j][k] > max1) {
					max1 = a[j][k];
					newx = j;//当前找到的最大值的坐标
					newy = k;
				}
			}
		}
		a[newx][newy] = 0;
		int dist = newx;
		if (i == 1) {
			k -= (newx + 1);
			if (dist > k) break;
			else ans += max1;
		}
		else {
			k -= (abs(newy - oldy) + abs(newx - oldx)) + 1;
			if (dist > k) break;
			else ans += max1;
		}
		oldy = newy;
		oldx = newx;
	}
	cout << ans;
	return 0;
}
