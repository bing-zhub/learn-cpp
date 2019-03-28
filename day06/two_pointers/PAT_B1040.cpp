#include <bits/stdc++.h>

using namespace std;

int main(){
    int maxN = 100010;
    char str[maxN];
    int leftNumP[maxN] = {0};
    cin >> str;

    int len = strlen(str);
    for(int i = 0; i < len; i++){
        if(i>0){
            leftNumP[i] = leftNumP[i-1];
        }
        if(str[i]=='P')
            leftNumP[i] ++;
    }

    int ans = 0, rightNumT = 0;
    for(int i = len -1; i >= 0; i --){
        if(str[i] == 'T')
            rightNumT ++;
        else if(str[i] == 'A')
            ans = (ans + leftNumP[i] * rightNumT)%1000000007; 
    }

    cout << ans;
    return 0;
}