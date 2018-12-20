#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int a[maxn];
int main() {
	int n;
	scanf("%d", &n);
	int maxx = 0, maxpos;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > maxx) {
			maxx = a[i];
			maxpos = i;
		}
	}
	int cnt = 1;
	for (int i = maxpos - 1; i >= 1; i--) {
		if (a[i] == maxx - 1) {
			cnt++;
			maxx -= 1;
		}
	}
	cout << n - cnt;
	return 0;
}