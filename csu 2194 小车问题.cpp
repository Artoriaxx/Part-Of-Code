#include<bits/stdc++.h>
#define maxn 1070
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
int main() {
	double s = getnum(), a = getnum(), b = getnum();
	double x = (b + a) * s / (b + 3 * a);
	printf("%.3lf\n", x / b + (s - x) / a);
	return 0;
}
