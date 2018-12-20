#include<bits/stdc++.h>
using namespace std;
inline int getnum() {
    int ans = 0; char c; int flag = 1;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') flag = -1; else ans = c - '0';
    while (isdigit(c = getchar())) ans = ans * 10 + c - '0';
    return ans * flag;
}
int a[150];
int main(){
    int n = getnum();
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = getnum();
        sum += a[i];
    }
    int avg = sum / n;
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] < avg){
            a[i + 1] -= avg - a[i];
            a[i] = avg;
            ans++;
        }
        else if (a[i] > avg){
            a[i + 1] += a[i] - avg;
            ans++;
            a[i] = avg;
        }
    }
    cout << ans;
    return 0;
}
