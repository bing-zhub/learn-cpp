#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;


double f(double x){
    return x*x;
}

double calSqrt(double l, double r, double x){
    double mid;
    while(r - l > eps){
        mid = (r+l)/2;
        if(f(mid) > x){
            r = mid;
        }else{
            l = mid;
        }
    }
    return mid;
}

int main(){
    cout << "sqrt(2)=" << calSqrt(1,2,2);
    return 0;
}