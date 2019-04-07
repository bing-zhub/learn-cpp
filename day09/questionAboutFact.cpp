#include <bits/stdc++.h>
using namespace std;

int main(){
    // 计算n!中有多少个质因子 详见P182
    int ans = 0;
    int n=10,p=2;
    while(n){
        ans += n/p;
        n/=p;
    }
    cout << ans << endl;
    return 0;
}