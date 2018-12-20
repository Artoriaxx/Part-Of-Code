#include<bits/stdc++.h>
using namespace std;
char s[10050];
int need[26] = {
	5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2,
};
int main() {
	while (scanf("%s", s + 1) != EOF) {
		int len = strlen(s + 1);
		int base_level = 25;
		int star = 0;
		bool flag = false;
		int success = 0;
		for (int i = 1; i <= len; i++) {
			if (s[i] == 'W') {
				if (flag && base_level >= 6) {
					star += 2;
				}
				else {
					star++;
					success++;
				}
				if (success >= 2) {
					flag = true;
				}
			}
			else {
				flag = false;
				success = 0;
				if (base_level <= 20) {
					if (!(base_level == 20 && star == 0)) {
						star--;
					}
				}
			}
			if (star < 0) {
				base_level++;
				star = need[base_level] - 1;
			}
			else if (star > need[base_level]) {
				star -= need[base_level];
				base_level--;
			}
			if (base_level == 0) break;
		}
		if (base_level) printf("%d\n", base_level);
		else printf("Legend\n");
	}
	return 0;
}