#include<stdio.h>
double change(double a) {
	if (a > 0) {
		a = int(a * 10 + 0.5) / 10.0;
	}
	if (a < 0) {
		a = int(a * 10 - 0.5) / 10.0;
	}
	return a;
}
const double eps = 1e-4;
double fabs(double a) {
	return a > 0 ? a : -a;
}
void print(double a, double b) {
	if (fabs(a) < eps && fabs(b) > eps) {
		printf("%.1lfi", b);
	}
	else if (fabs(a) < eps && fabs(b) < eps) {
		printf("0.0");
	}
	else if (fabs(a) > eps && fabs(b) < eps) {
		printf("%.1lf", a);
	}
	else {
		if (b > 0) {
			printf("%.1lf+%.1lfi", a, b);
		}
		else {
			printf("%.1lf%.1lfi", a, b);
		}
	}
	
}
int main() {
	double a1, b1, a2, b2;
	scanf("%lf%lf%lf%lf", &a1, &b1, &a2, &b2);
	double plus1 = a1 + a2;
	double plus2 = b1 + b2;
	double minus1 = a1 - a2;
	double minus2 = b1 - b2;
	double mul1 = a1 * a2 - b1 * b2;
	double mul2 = a1 * b2 + a2 * b1;
	double div1 = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2);
	double div2 = (a2 * b1 - a1 * b2) / (a2 * a2 + b2 * b2);
	printf("("); print(a1, b1); printf(")"); printf(" + "); printf("("); print(a2, b2); printf(")"); printf(" = ");
	plus1 = change(plus1); plus2 = change(plus2);
	print(plus1, plus2);
	printf("\n");
	printf("("); print(a1, b1); printf(")"); printf(" + "); printf("("); print(a2, b2); printf(")"); printf(" = ");
	minus1 = change(minus1); minus2 = change(minus2);
	print(minus1, minus2);
	printf("\n");
	printf("("); print(a1, b1); printf(")"); printf(" + "); printf("("); print(a2, b2); printf(")"); printf(" = ");
	mul1 = change(mul1); mul2 = change(mul2);
	print(mul1, mul2);
	printf("\n");
	printf("("); print(a1, b1); printf(")"); printf(" + "); printf("("); print(a2, b2); printf(")"); printf(" = ");
	div1 = change(div1); div2 = change(div2);
	print(div1, div2);
	return 0;
}