//
// Created by Öì±ø on 2019/8/27.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510, INF = 0x3f3f3f3f;
int g[N][N], dist[N], n, m;
bool st[N];

int dijkstra(){
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j])
                if(t == -1 || dist[t] > dist[j])
                    t = j;
        st[t] = true;
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if(dist[n] == INF) return -1;
    return dist[n];
}

int main(){
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = min(g[a][b], w);
    }
    cout << dijkstra() << endl;
    return 0;
}