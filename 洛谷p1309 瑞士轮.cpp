#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
inline int getnum() {
	int ans = 0; char c; int flag = 1;
	while (!isdigit(c = getchar()) && c != '-');
	if (c == '-') flag = -1; else ans = c - '0';
	while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
	return ans * flag;
}
struct node {
	int val, id, pow;
	bool operator < (const node &a) const {
		if (val == a.val) return id < a.id;
		else return val > a.val;
	}
} competitor[maxn], q1[maxn], q2[maxn];
//bool cmp(node a, node b) {
//	if (a.val == b.val) return a.id < b.id;
//	else return a.val > b.val;
//}

int ans[maxn];
int main() {
	int n = getnum(), r = getnum(), q = getnum();
	for (int i = 1; i <= 2 * n; i++) {
		competitor[i].val = getnum();
		competitor[i].id = i;
	}
	for (int i = 1; i <= 2 * n; i++) {
		competitor[i].pow = getnum();
	}
	sort(competitor + 1, competitor + 2 * n + 1);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= 2 * n; j += 2) {
			node person1 = competitor[j];
			node person2 = competitor[j + 1];
			if (person1.pow > person2.pow) {
				person1.val++;
				q1[(j + 1) / 2] = person1;
				q2[(j + 1) / 2] = person2;
			}
			else {
				person2.val++;
				q1[(j + 1) / 2] = person2;
				q2[(j + 1) / 2] = person1;
			}
		}
		merge(q1 + 1, q1 + n + 1, q2 + 1, q2 + n + 1, competitor + 1);
	}
	cout << competitor[q].id;
	return 0;
}