#include<stdio.h>
#define maxn 100050
int a[maxn];
void qsort(int a[], int *l, int *r) {
	int *i, *j;
	i = l; j = r;
	int *key;
	key = l + (r - l) / 2;
	while (i <= j) {
		while (*i < *key) i++;
		while (*j > *key) j--;
		if (i <= j) {
			int tmp = *i;
			*i = *j;
			*j = tmp;
			i++;
			j--;
		}
	}
	if (i < r) qsort(a, i, r);
	if (j > l) qsort(a, l, j);
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, &a[1], &a[n]);
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}