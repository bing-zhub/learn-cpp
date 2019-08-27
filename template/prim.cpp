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
// 输出样例：
//  6

#include <iostream>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int g[N][N], dist[N], n, m;
bool st[N];

int prim(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j])
                if(t == -1 || dist[t] > dist[j])
                    t = j;
        st[t] = true;
        if(i && dist[t] == INF) return INF;
        if(i) ret += dist[t];
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);
    }
    return ret;
}

int main(){
    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    while(m--){
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = g[b][a] = min(g[a][b], w);
    }
    int ret = prim();
    if(ret > INF / 2) cout << "impossible";
    else cout << ret;
    return 0;
}
