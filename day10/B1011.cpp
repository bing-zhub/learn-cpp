#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cout << "Case #"<<i+1<<": ";
        if(a+b>c)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}