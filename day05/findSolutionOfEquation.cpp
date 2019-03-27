#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-5;

double f(double x){
    return x * x - 5;
}

double solve(double l, double r){
    double mid;
    while( r - l > eps){
        mid = (l+r)/2;
        if(f(mid)>0){
            r = mid;
        }else{
            l = mid;
        }
    }
    return mid;
}

 
int main(){
    cout << "x^2 - 5 = 0, where x = " << solve(2, 3); // f(x) 必须在区间[l,r]单调, 且单调增, 否则修改condition
    return 0;
}