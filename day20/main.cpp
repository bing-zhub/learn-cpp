#include <iostream>
using namespace std;

int sqrt(int x){
    int l = 0, r = x;
    int mid = l;
    while(x - mid * mid > 1e-1){
        mid = l + r >> 1;
        cout << l << " " << r << " " << mid << endl;
        if(mid * mid <= x){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return mid;
}

int main(){
    int x;
    cin >> x;
    cout << sqrt(x);
    return 0;
}