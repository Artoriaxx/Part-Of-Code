#include<bits/stdc++.h>
#define maxn 1000020
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
char a[maxn];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n = getnum();
		scanf("%s", a + 1);//慎用getchar读入单个字符，血的教训！！！！
		int ans = 0, cnt = 0, finalans = 0, r = 0, l = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == '0') ans++;
			else cnt++;
			r = cnt - ans;
			finalans = max(finalans, l - r);
			l = max(l, r);
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == '1') finalans++;
		}
		cout << finalans << endl;
	}
	return 0;
}