#include<bits/stdc++.h>
#include<set>
using namespace std;
set<int> s;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		s.insert(a);
	}
	set<int>::iterator it;
	cout << s.size() << '\n';
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	return 0;
}