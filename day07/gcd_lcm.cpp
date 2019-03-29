#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    cout << gcd(7,14)<<endl;
    cout << lcm(7,14);
    return 0;
}