#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int a[25];
int main() {
	int n = getnum(), m = getnum();
	int ans = 0, ans1 = 0;
	for (ll i = 1; i <= (1 << n) - 1; i++) {
		int tmp = i, cnt = 0, sum = 0, cnt1 = 0;
		while (tmp) {
			cnt++;
			if (tmp & 1) {
				sum += cnt;
				cnt1++;
				a[cnt1] = cnt;
			}
			tmp >>= 1;
		}
		if (sum == m) {
			ans++;
			for (int i = 1; i <= cnt1; i++) {
				cout << a[i] << " ";
			}
			cout << '\n';
		}
		if (sum == m && cnt1 == 5) ans1++;
	}
	cout << ans << " " << ans1;
	return 0;

}