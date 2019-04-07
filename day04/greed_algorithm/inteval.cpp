#include <bits/stdc++.h>
using namespace std;

const int maxN = 110;

struct inteval{
    int x,y;
} intevals[maxN];

bool cmp(const inteval i1, const inteval i2){
    if(i1.x != i2.x)
        return i1.x > i2.x; // 左端点大的放前面
    else return 
        i1.y < i2.y;  // 右端点小的放前面
}

int main(){
    int n;
    while(cin>>n, n!=0){
        for(int i = 0; i < n; i++){
            cin >> intevals[i].x >> intevals[i].y;
        }
        sort(intevals, intevals + n, cmp);
        int ans = 1, lastX = intevals[0].x;
        for(int i = 1; i < n; i++){
            if(intevals[i].y >= lastX){
                ans++;
                lastX = intevals[i].x;
            }
        }
        printf("%d", ans);
    }
    return 0;
}