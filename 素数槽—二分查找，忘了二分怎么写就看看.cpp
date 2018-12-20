#include<bits/stdc++.h>
#define maxn 1300050
using namespace std;
int notprime[maxn], prime[maxn / 10];
void find_prime(int n) {
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (!notprime[i]) prime[++cnt] = i;
		for (int j = 1; j <= cnt && prime[j] * i <= n; j++) {
			notprime[prime[j] * i] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}
int l, r;
void find(int x) {
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (prime[mid] > x) {
			r = mid - 1;
		}
		else l = mid + 1;
	}
}
//������֮��lһ����r��1����Ϊ������r=mid-1��ֹ��ѭ������l=mid+1��ֹ��
//ѭ������ʹ��l��r��
int main() {
	int n;
	scanf("%d", &n);
	find_prime(maxn);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		l = 1; r = 100000;
		if (!notprime[x]) {
			cout << "0" << "\n";
			continue;
		}
		find(x);
		int ans = prime[l] - prime[l - 1];
		cout << ans << "\n";
	}
}