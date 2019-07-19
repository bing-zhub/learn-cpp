![05405-vbp6uyqe2p.png](http://images.zshaopingb.cn/2019/07/3596239028.png)
## 最小生成树(无向图)
### Prim算法
#### 朴素版Prim算法 O(n^2) -- 稠密图
- dist[i] <- INF
- for(i=0; i<= n; i++) 
    t <- 集合外距离最近的点
    用t更新其他点到集合的距离
    s[t] = true;
``` C++
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
const int N = 510, INF = 0x3f3f3f3f;
// dist[i] -> i到集合的距离 区分于Dijkstra
int dist[N], g[N][N];
bool st[N];

int prim(){
    int ret = 0;
    for(int i = 0; i < n; i++){
        int t = -1;
        for(int j = 1; j <= n; j++)
            if(!st[j] && ( t == -1 || dist[t] > dist[j]))
                t = j;
        // 不是第一个点
        // 当前距离最近的点到集合的距离还是正无穷, 则不存在最小生成树
        if(i && dist[t] == INF) return INF;
        if(i) ret += dist[t];
        for(int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    
    return ret;
}

int main(){
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[b][a] =  g[a][b] = min(g[a][b], c);
    }
    int t = prim();
    
    if(t == INF) puts("impossible");
    else printf("%d\n", t);
    return 0;
}
```
#### 堆优化的Prim算法 O(mlogn) -- 不常用
### Kruskal算法 O(mlogm)-- 稀疏图
## 二分图
### 如何判别 -- 染色法 -- O(n+m)
### 匈牙利算法 -- 二分图的最大匹配 -- O(mn)