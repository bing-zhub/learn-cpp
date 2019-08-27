//
// Created by Öì±ø on 2019/8/27.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210, INF = 0x3f3f3f3f;
int g[N][N], n, m, q;

void floyd(){
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main(){
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i==j) g[i][j] = 0;
            else g[i][j] = INF;

    while(m--){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }

    floyd();

    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        int res = g[a][b];
        if(res > INF / 2) puts("impossible");
        else printf("%d\n", res);
    }

    return 0;
}