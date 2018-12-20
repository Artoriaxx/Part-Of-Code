#include<bits/stdc++.h>
#define maxn 100050
#define maxl 1000050
using namespace std;
char s[maxn];
int vis[maxl];
int main() {
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i++) {
		int tmp = 0;
		for (int j = i; j <= i + 18 && j <= len; j++) {
			tmp = tmp * 2 + s[j] - '0';//因为长度为17的01串的种类的和超过了1e5
			//所以题中所给的1e5的串必然能够由长度为17及以下的串构成
			vis[tmp] = 1;
		}
	}
	int i = 0;
	while (1) {
		if (!vis[i]) {
			if (i == 0) {
				printf("1");
				return 0;
			}
			else {
				printf("%d", int(log2(i)) + 1);
				return 0;
			}
		}
		i++;
	}
}