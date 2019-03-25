#include <bits/stdc++.h>
using namespace std;

int Fact(int n ){
    if(n == 0)
        return 1;
    else
        return Fact(n-1) * n;
}

int main(){
    int n;
    cin >> n;
    cout << Fact(n);
    return 0;
}