#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    s = s % n;
    int arr[n] = {0};

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(s==0){
        for(int i =0; i < n; i++)
            if(i==0)
                cout << arr[i];
            else
                cout << " " << arr[i];
        return 0;
    }
        

    for(int i = n - s; i < n; i++){
        if(i==n-s)
            cout << arr[i];
        else
            cout << " " << arr[i];
    }

    for(int i = 0; i < n-s; i ++){
        cout << " " << arr[i];
    }
    return 0;
}