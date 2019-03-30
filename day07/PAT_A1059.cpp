// bug not found 23/25

#include <bits/stdc++.h>
using namespace std;

int maxN = 10000;
int primeNums[10001], pNums = 0;
bool isP[10001];
struct factor{
    int p,count;
} f[10];

void findPrime(){
    for(int i = 2; i < maxN; i++){
        if(isP[i]==false){ // 反转是因为初始化全是false
            primeNums[pNums++] = i;
            for(int j = i; j < maxN; j+=i)
                isP[j] = true;
        }
    }
}

int main(){
    int x;
    cin >> x;
    int t = x;
    findPrime();
    int i = 0;
    for(int j = 0; j < maxN && x > 1; j++){
        if(x%primeNums[j]==0){
            f[i].p = primeNums[j];
            f[i].count = 0; 
            while(x%primeNums[j]==0){
                f[i].count++;
                x/=primeNums[j];
            }
            i++;
        }
    }
    cout << t <<"=";
    for(int i =0; i < 10; i++){
        if(f[i].p!=0){
            if(!i)
                cout << f[i].p;
            else
                cout << "*" << f[i].p;
            if(f[i].count>1)
                cout << "^"<<f[i].count;            
        }
    }
    return 0;
}