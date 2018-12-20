#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
void quicksort(int a[], int l, int r) {
	int i = l, j = r;
	int key = a[(l + r) >> 1];//ѡȡ�м�Ԫ�أ���Ϊ�м�Ԫ�ػ�仯�����Բ����ױ���
	while (i <= j) {
		while (a[i] < key) i++;//����ӵ��ұ�ȥ��С���ӵ����ȥ
		while (a[j] > key) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (i < r) quicksort(a, i, r);
	if (j > l) quicksort(a, l, j);
}
int a[maxn];
int main() {
	int n = getnum();
	for (int i = 1; i <= n; i++) {
		a[i] = getnum();
	}
	quicksort(a, 1, n);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}