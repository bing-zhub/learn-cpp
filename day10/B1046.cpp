#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ad=0,bd=0;
    for(int i = 0;i < n;i++){
        int as,bs,ah,bh;
        cin >> as >> ah >> bs >> bh;
        if(ah == as + bs && bh != as + bs)
            bd ++;
        if(ah != as + bs && bh == as + bs)
            ad++;
    }
    cout << ad << " " << bd;
    return 0;
}