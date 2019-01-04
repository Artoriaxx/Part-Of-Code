#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	while (1) {
		s.clear();
		getline(cin, s);
		if (s == "0000 0000 0000 0000") break;
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < s.length(); i++) {
			int x = i + 1;
			if (x % 2 == 1) {
				sum1 += ((s[i] - '0') * 2 > 9) ? ((s[i] - '0') * 2 - 9) : (s[i] - '0') * 2;
			}
			else {
				sum2 += s[i] - '0';
			}
		}
		if ((sum1 + sum2) % 10 == 0) {
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}