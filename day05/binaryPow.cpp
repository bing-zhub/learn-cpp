#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//a^b
ll binaryPow(ll a, ll b){ // O(logb)
    if(b==0) return 1;
    if(b&1) return a * binaryPow(a, b-1);
    else{
        ll t = binaryPow(a, b/2);
        return t * t;
    }
}

int main(){
    cout << "2^35 = " << binaryPow(2, 35) << endl;
    return 0;
}