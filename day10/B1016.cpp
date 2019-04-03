#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,a,b;
    int ra = 0, rb = 0;
    cin >> m >> a >> n >> b;
    while(m>0){
        if(m%10==a)
            ra = ra*10 + a;
        m/=10;
    }

    while(n>0){
        if(n%10==b)
            rb = rb*10 + b;
        n/=10;
    }
    cout << ra+rb;
    return 0;
}