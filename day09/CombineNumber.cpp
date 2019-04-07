// chinese English
#include <bits/stdc++.h>
using namespace std;

long long res[67][67] = {0};

//C(n,m) = C(n-1, m) + C(n-1, m-1);
//从n个数里面选取m个数, 可分为两种, 1.从前n-1个数里面选m种 2.从前n-1个数里面选m-1个, 再算上最后一个.
long long C(long long n, long long m){
    if(m==0 || m == n) return 1;
    if(res[n][m] != 0 ) return res[n][m]; // 大量重复 记录下来 以防计算冗余
    else res[n][m] = C(n-1, m) + C(n-1, m-1); // 语法问题, 记录下来, 再返回
}

//C(m,n)%p
long long C1(long long n, long long m, int p){
    if(m==0 || m == n) return 1;
    if(res[n][m] != 0 ) return res[n][m]; // 大量重复 记录下来 以防计算冗余
    else res[n][m] = (C(n-1, m) + C(n-1, m-1))%p; // 语法问题, 记录下来, 再返回
}

int main(){

    return 0;
}