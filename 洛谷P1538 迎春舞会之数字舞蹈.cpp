#include<stdio.h>
#include<string.h>
int code[11][6] = { 
	{ 1,3,0,3,1 },{ 0,2,0,2,0 },{ 1,2,1,1,1 },
	{ 1,2,1,2,1 },{ 0,3,1,2,0 },{ 1,1,1,2,1 },
	{ 1,1,1,3,1 },{ 1,2,0,2,0 },{ 1,3,1,3,1 },
	{ 1,3,1,2,1 } };
//code[a][b]代表数字a第b行的编码
//如果b==0 || b == 2 || b == 4代表的是输出横杠的行，此时只有两种编码，0或1,0代表没有横杠，1代表有横杠
//其他情况代表的输出竖杠的行，此时3种编码，1代表左侧有竖杠，2代表右侧有竖杠，3代表两侧都有竖杠
void draw(int a, int b, int size) {
	if (b % 2 == 0) {
		if (code[a][b] == 0) {
			for (int i = 1; i <= size + 2; i++) putchar(' ');
		}
		else {
			putchar(' ');
			for (int i = 1; i <= size; i++) putchar('-');
			putchar(' ');
		}
	}
	else if (b % 2 == 1) {
		if (code[a][b] == 1) {
			putchar('|');
			for (int i = 1; i <= size; i++) putchar(' ');
			putchar(' ');
		}
		if (code[a][b] == 2) {
			putchar(' ');
			for (int i = 1; i <= size; i++) putchar(' ');
			putchar('|');
		}
		if (code[a][b] == 3) {
			putchar('|');
			for (int i = 1; i <= size; i++) putchar(' ');
			putchar('|');
		}
	}
	putchar(' ');
}
int main() {
	int n;
	char str[250];
	scanf("%d%s", &n, str);
	int len = strlen(str);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= (i % 2 == 1 ? 1 : n); j++) {
			for (int k = 0; k < len; k++) {
				draw(str[k] - 48, i - 1, n);
			}
			putchar('\n');
		}
	}
	return 0;
}