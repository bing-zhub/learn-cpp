#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int aWin = 0, even=0, bWin=0;
    for(int i = 0; i < n; i++){
        char a,b;
        cin >> a >> b;
        if(a!=b){
            if(a=='C'){
                if(b=='J')
                    aWin++;
                else
                    bWin++;
            }else if(a=='J'){
                if(b=='B')
                    aWin++;
                else
                    bWin++;
            }else if(a=='B'){
                if(b=='C')
                    aWin++;
                else
                    bWin++;
            }
        }else {
            even++;
        }
    }
    cout << aWin << " " << even << " " << bWin << endl;
    cout << bWin << " " << even << " " << aWin << endl;
    return 0;
}