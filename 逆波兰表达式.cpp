#include<stdio.h>
#include<stack>
#include<ctype.h>
using namespace std;
stack<int> num;
int main() {
	bool flag = 1;
	while (1) {
		if (flag) printf("Enter an PRN expression: ");
		flag = 0;
		char c;
		scanf("%s", &c);
		if (isdigit(c)) num.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '='){
			int a, b;
			if (c != '=') {
				a = num.top(); num.pop();
				b = num.top(); num.pop();
			}
			switch (c) {
			case '+':
				num.push(a + b); break;
			case '-':
				num.push(b - a); break;
			case '*':
				num.push(a * b); break;
			case '/':
				num.push(b / a); break;
			case '=':
				printf("Value of expression: %d\n", num.top());
				flag = 1;
				num.pop();
				break;
			}
		}
		else break;
	}
	return 0;
}