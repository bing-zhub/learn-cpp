#include <bits/stdc++.h>
using namespace std;

const int n = 54;
const char mp[5] = {'S', 'H', 'C', 'D', 'J'};
int start[n+1], _next[n+1], _end[n+1];

int main(){
    for(int i = 1; i <= n; i++){
        start[i] = i;
    }
    int steps;
    cin >> steps;
    for(int i = 1; i <=n; i++){
        cin >> _next[i];
    }
    for(int step = 0; step < steps; step++){
        for(int i = 1; i <=n; i++){
            _end[_next[i]] = start[i]; 
        }
        for(int i = 1; i <=n; i++){
            start[i] = _end[i]; 
        }
    }

    for(int i = 1;i <=n;i++){
        if(i!=1)
            cout << " ";
        _end[i]--;
        cout << mp[_end[i]/13] << _end[i]%13+1;
    }
    return 0;
}