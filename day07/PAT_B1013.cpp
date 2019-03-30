#include <bits/stdc++.h>
using namespace std;

int maxN = 10000;
int primeNums[10001], pNums = 0;
bool isP[10001];

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
    int m,n;
    cin >> m >> n;
    findPrime();
    int ns = 1;
    for(int i = m -1; i < n; i++){
        if(ns%10==1)
            cout << primeNums[i];
        else if(ns%10==0)
            cout << " " << primeNums[i] << endl; 
        else
            cout << " " << primeNums[i];
        ns++;
    }
    return 0;
}