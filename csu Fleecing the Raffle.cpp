#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, p;
	while (scanf("%d%d", &n, &p) != EOF) {
		double now = (double)p / (double)(n + 1.0);
		double ans = 0.0;
		int x = 2;
		while (1) {
			if (ans > now) break;
			else ans = now;
			now *= (double)x / (double)(x - 1.0) * (double)(n + x - p) / (double)(n + x);
			x++;
		}
		printf("%.11lf", ans);
	}
}