#include <bits/stdc++.h>
using namespace std;

int main(){
    int count[5] = {0}, ans[5] = {0};
    int n, tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp%5==0 && tmp%2==0){
            ans[0] += tmp;
        }else if(tmp%5==1){
            ans[1] += pow(-1, count[1]) * tmp;
            count[1] ++;
        }else if(tmp%5==2){
            ans[2] ++;
        }else if(tmp%5==3){
            ans[3] += tmp;
            count[3] ++;
        }else if(tmp%5==4){
            if(tmp>ans[4])
                ans[4] = tmp;
        }
    }

    for(int i = 0; i < 5; i++){
        if(i==0){
            if(ans[i]==0)
                cout << "N";
            else
                cout << ans[i];
        }else{
            if(ans[i]==0)
                cout << " N";
            else if(i==3)
                printf(" %.1f",ans[i]*1.0/count[i]);
            else
                cout << " " << ans[i];
        }    
    }

    return 0;
}