//
// Created by 朱兵 on 2019/8/27.
//

// 输入样例：
//  4 5
//  1 2 1
//  1 3 2
//  1 4 3
//  2 3 2
//  3 4 4
//
// 输出样例：
//  6

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
int n, m, p[N];
struct edge{
    int a, b, w;
} edges[N];

bool cmp(edge a, edge b) { return a.w < b.w; }

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) cin >> edges[i].a >> edges[i].b >> edges[i].w;

    sort(edges, edges+m, cmp);

    for(int i = 1; i <= n; i++) p[i] = i;
    int cnt = 0, res = 0;
    for(int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a);
        b = find(b);
        if(a!=b){
            p[a] = b;
            cnt ++;
            res += w;
        }
    }
    if(cnt < n - 1) cout << "impossible" << endl;
    else printf("%d\n", res);
    return 0;
}