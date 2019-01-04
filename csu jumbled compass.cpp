#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		if (abs(n - m) == 180) cout << 180 << endl;
		else {
			int x = m - n;
			if (abs(x) > 180) {
				if (x > 0) {
					x -= 360;
				}
				else {
					x += 360;
				}
			}
			cout << x << endl;
		}
	}
	return 0;
}