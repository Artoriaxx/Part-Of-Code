#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[50];
ll two[20];
int mon[13] = {
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
bool isornot(int a) {
	return a % 4 == 0 && a % 100 != 0 || a % 400 == 0;
}
int main() {
	int n, m;
	map<int, int> q;
	scanf("%d%d", &m, &n);
	two[0] = 1;
	for (int i = 1; i <= 18; i++) {
		two[i] = 2 * two[i - 1];
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		q[x] = ++cnt;
	}
	for (int i = 1; i <= n; i++) {
		int pos = 0, year = 0, month = 0, day = 0;
		long long check = 0;
		mon[2] = 28;
		scanf("%s", s + 1);
		for (int i = 1; i <= 6; i++) {
			pos = pos * 10 + s[i] - '0';
			check += (s[i] - '0') * two[18 - i];
		}
		if (q.find(pos) == q.end()) {
			printf("Invalid\n");
			continue;
		}
		for (int i = 7; i <= 10; i++) {
			year = year * 10 + s[i] - '0';
			check += (s[i] - '0') * two[18 - i];
		}
		if (year < 1900 || year > 2011) {
			printf("Invalid\n");
			continue;
		}
		if (isornot(year)) mon[2] = 29;
		for (int i = 11; i <= 12; i++) {
			month = month * 10 + s[i] - '0';
			check += (s[i] - '0') * two[18 - i];
		}
		if (month == 0 || month > 12) {
			printf("Invalid\n");
			continue;
		}
		for (int i = 13; i <= 14; i++) {
			day = day * 10 + s[i] - '0';
			check += (s[i] - '0') * two[18 - i];
		}
		if (day > mon[month] || day == 0) {
			printf("Invalid\n");
			continue;
		}
		if (s[15] == '0' && s[16] == '0' && s[17] == '0') {
			printf("Invalid\n");
			continue;
		}
		for (int i = 15; i <= 17; i++) {
			check += (s[i] - '0') * two[18 - i];
		}
		int num;
		if (s[18] == 'X') num = 10;
		else num = s[18] - '0';
		if ((num + check) % 11 != 1) {
			printf("Invalid\n");
			continue;
		}
		if ((s[17] - '0') % 2 == 0) {
			printf("Female\n");
		}
		else {
			printf("Male\n");
		}
	}
	return 0;
}