#include<stdio.h>
#include<string.h>
int code[11][6] = { 
	{ 1,3,0,3,1 },{ 0,2,0,2,0 },{ 1,2,1,1,1 },
	{ 1,2,1,2,1 },{ 0,3,1,2,0 },{ 1,1,1,2,1 },
	{ 1,1,1,3,1 },{ 1,2,0,2,0 },{ 1,3,1,3,1 },
	{ 1,3,1,2,1 } };
//code[a][b]��������a��b�еı���
//���b==0 || b == 2 || b == 4������������ܵ��У���ʱֻ�����ֱ��룬0��1,0����û�к�ܣ�1�����к��
//������������������ܵ��У���ʱ3�ֱ��룬1������������ܣ�2�����Ҳ������ܣ�3�������඼������
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