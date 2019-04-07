#include <bits/stdc++.h>
using namespace std;
const int maxN = 10005;
int dis[maxN], A[maxN];

int main(){
    int n, sum=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        sum += A[i];
        dis[i] = sum;
    }
    int querys;
    cin >> querys;
    int l,r;
    for(int i = 0; i < querys; i++){
        cin >> l >> r;
        if(l>r) swap(l,r);
        int t = dis[r-1] - dis[l-1];
        printf("%d\n",min(t, sum -t));
    }
    return 0;
}