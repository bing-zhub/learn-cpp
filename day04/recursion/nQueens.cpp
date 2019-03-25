#include <bits/stdc++.h>
using namespace std;

const int maxN = 11;
int nums = 0;
int n, P[maxN], hashTable[maxN] = {false};
void generate(int index){ 
    if(index == n+1){
        bool flag = true;
        for(int i = 1; i <= n; i++){
            for(int j = i +1; j <= n; j++){
                if(abs(i-j)==abs(P[i] - P[j])){
                    flag = false;
                }
            }
        }
        if(flag) nums ++;
        return;
    }

    for(int i = 1; i <=n; i++){
        if(hashTable[i] == false){
            P[index] = i;
            hashTable[i] = true;
            generate(index + 1);
            hashTable[i] = false;
        }
    }

}

int main(){
    n = 8;
    generate(1);
    cout << nums;
    return 0;
}