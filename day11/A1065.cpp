#include <bits/stdc++.h>
using namespace std;

int main(){
    int index = 1, n;
    cin >> n;
    while(n--){
        long long a,b,c;
        cin >> a >> b >> c;
        long long res = a + b;
        bool flag = false;
        if(a > 0 && b > 0 && res < 0) flag = true;
        else if(a < 0 && b < 0 && res >= 0) flag = false;
        else if(res > c) flag = true;
        else flag = false;
        if(flag)
            cout << "Case #" << index++ <<": true"<<endl; 
        else
            cout << "Case #" << index++ <<": false"<<endl; 
    }
    return 0;
}