#include <bits/stdc++.h>
using namespace std;

int v[10000];

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    int count =0, max = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && b[i] > max){
            v[count++] = b[i]; 
        }

        if(b[i] > max)
            max = b[i];
    }

    cout << count << endl;
    for(int i = 0; i < count; i++){
        if(i==0)
            cout << v[i];
        else
            cout << " " << v[i];
    }

    return 0;
}