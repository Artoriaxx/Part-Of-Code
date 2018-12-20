#include<bits/stdc++.h>
using namespace std;
int a[15];
int ans;
int n;
int cnt;
stack<int> number;
void dfs(int x) {
	if (x >= 9) {
		int sum = 0;
		number.push(1);
		for (int i = 2; i <= 9; i++) {
			if (a[i - 1] == 1) {
				number.push(i);
			}
			else if (a[i - 1] == 2) {
				number.push(-i);
			}
			else {
				int t = number.top(); number.pop();
				number.push(t * i);
			}
		}
		while (!number.empty()) {
			sum += number.top(); number.pop();
		}
		if (sum == n) ans++;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		a[x] = i;
		dfs(x + 1);
	}
}
int main() {
	scanf("%d", &n);
	dfs(1);
	cout << ans;
	return 0;
}