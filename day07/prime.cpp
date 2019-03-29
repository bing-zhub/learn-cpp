#include <bits/stdc++.h>
using namespace std;

int maxN = 101;
int primeNums[101], pNums = 0;
bool isP[101];

bool isPrime(int a){
    int t = sqrt(a*1.0);
    if(a==1) return false;
    for(int i = 2; i<= t; i++)
        if(a%i==0)
            return false;
    return true;
}

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
    // for(int i = 1; i < maxN; i++){
    //     if(isPrime(i))
    //         primeNums[pNums++] = i;
    // } 
    findPrime();
    for(int i = 0; i < pNums; i++){
        cout << primeNums[i] << " ";
    }
    return 0;
}