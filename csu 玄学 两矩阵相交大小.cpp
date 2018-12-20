#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		ll x1, y11, x2, y22, x3, y33, x4, y44;
		scanf("%lld%lld%lld%lld", &x1, &y11, &x2, &y22);
		scanf("%lld%lld%lld%lld", &x3, &y33, &x4, &y44);
		ll minx1 = min(x1, x2), miny1 = min(y11, y22);
		ll maxx1 = max(x1, x2), maxy1 = max(y11, y22);
		ll minx2 = min(x3, x4), miny2 = min(y33, y44);
		ll maxx2 = max(x3, x4), maxy2 = max(y33, y44);
		ll minx = max(minx1, minx2), miny = max(miny1, miny2);
		ll maxx = min(maxx1, maxx2), maxy = min(maxy1, maxy2);
		if (minx > maxx || miny > maxy || (minx > minx1 && miny > miny1 && maxx < maxx1 && maxy < maxy1) || (minx > minx2 && miny > miny2 && maxx < maxx2 && maxy < maxy2)) {
			printf("Invalid!\n");
			continue;
		}
		else {
			ll ans = (maxx1 - minx1) * (maxy1 - miny1) - (maxx - minx) * (maxy - miny) + (maxx2 - minx2) * (maxy2 - miny2);
			printf("%lld\n", ans);
		}
	}
	return 0;
}