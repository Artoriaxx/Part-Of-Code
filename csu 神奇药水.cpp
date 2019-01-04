#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	set<int> s1, s2;
	while (scanf("%d", &n) != EOF) {
		s1.clear();
		s2.clear();
		for (int i = 1; i <= n; i++) {
			int q;
			scanf("%d", &q);
			double x1, y1;
			scanf("%lf%lf", &x1, &y1);
			int x = x1 * 100, y = y1 * 100;
			switch (q) {
			case 1:
				s1.insert(x);
				break;
			case -1:
				s1.erase(x);
				break;
			case 0:
				if (s1.empty()) {
					printf("No\n");
					break;
				}
				else if (*s1.begin() <= x && *(--s1.end()) >= x){
					printf("Yes\n");
					break;
				}
				else {
					printf("No\n");
					break;
				}
			}
		}
	}
	return 0;
}