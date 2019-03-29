#include <bits/stdc++.h>
using namespace std;

void to_array(int n, int num[]){
    for(int i = 0; i < 4; i++){
        num[i] = n%10;
        n/=10;
    }
}

int to_int(int num[]){
    int sum = 0;
    for(int i = 0; i <4 ; i++){
        sum = num[i] + sum*10;
    }
    return sum;
}

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n, num[4];
    cin >> n;
    while(true){
        to_array(n, num);
        sort(num, num+4, cmp);
        int a = to_int(num);
        sort(num, num+4);
        int b = to_int(num);
        printf("%04d - %04d = %04d\n", a, b, a-b);
        if(a-b==6174|| a-b ==0)
            break;
        else
            n = a-b;
        
    }
    return 0;
}