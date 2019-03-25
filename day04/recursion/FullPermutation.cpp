#include <bits/stdc++.h>
using namespace std;

const int maxN = 11;

// n的全排列 P暂存 hashTable表征数据是否被使用过 
int n, P[maxN], hashTable[maxN] = {false};
void generate(int index){ // 从第index位开始全排列
    if(index == n+1){ // 递归边界 
        for(int i = 1; i <= n; i++){ 
            printf("%d", P[i]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++){
        if(hashTable[i]==false){
            P[index] = i;
            hashTable[i] = true;
            generate(index + 1);  // 产生第index的全排列
            hashTable[i] = false; // 置回false
        }
    }

}

int main(){
    n = 3;
    generate(1);
    return 0;
}