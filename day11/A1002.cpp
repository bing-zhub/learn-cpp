#include <bits/stdc++.h>
using namespace std;

float arr[1010] = {0};

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        // a*x^b
        // arr[i]*x^i
        for(int i = 0; i < n; i++){
            int b;
            float a;
            cin >> a >> b;
            arr[b] += a; 
        }
    }

    int count = 0;
    for(int i = 0; i < 1010; i++){
        if(arr[i]!=0) count ++;
    }
    cout << count;
    for(int i =1009; i >=0 ;i--){
        if(arr[i]!=0) cout <<" " << arr[i] << " " << i;
    }

    return 0;
}