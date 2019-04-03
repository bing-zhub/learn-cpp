#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t1, t2;
    cin >> t1 >> t2;
    t1 = t2 - t1;
    if(t1%100 >= 50)
        t1 = t1 / 100 +1;
    else
        t1 = t1 / 100;
    
    printf("%02d:%02d:%02d",t1/3600,t1%3600/60, t1%60);

    return 0;   
}