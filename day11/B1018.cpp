#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int aWin = 0, even=0, bWin=0;
    // bcj
    int aR[3]={0}, bR[3]={0};
    for(int i = 0; i < n; i++){
        char a,b;
        cin >> a >> b;
        if(a!=b){
            if(a=='C'){
                if(b=='J'){
                    aWin++;
                    aR[1]++;
                }else{
                    bWin++;
                    bR[0]++;
                }
            }else if(a=='J'){
                if(b=='B'){
                    aWin++;
                    aR[2]++;
                }else{
                    bWin++;
                    bR[1]++;
                }
            }else if(a=='B'){
                if(b=='C'){
                    aWin++;
                    aR[0]++;
                }else{
                    bWin++;
                    bR[2]++;
                }
            }
        }else {
            even++;
        }
    }

    int maxA=-1, maxB=-1;
    int maxAi=-1, maxBi=-1;
    for(int i = 0; i < 3; i++){
        if(aR[i]>maxA){
            maxA = aR[i];
            maxAi = i;
        }
        if(bR[i]>maxB){
            maxB = bR[i];
            maxBi = i;
        }
    }
    cout << aWin << " " << even << " " << bWin << endl;
    cout << bWin << " " << even << " " << aWin << endl;
    if(maxAi==0) cout << "B ";
    else if(maxAi==1) cout << "C ";
    else if(maxAi==2) cout << "J ";

    if(maxBi==0) cout << "B";
    else if(maxBi==1) cout << "C";
    else if(maxBi==2) cout << "J";
    
    return 0;
}