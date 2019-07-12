# 最短路
只用考虑有向图就好
![21692-py5wls88wwk.png](http://images.zshaopingb.cn/2019/07/164444866.png)
## 单源最短路
一个点到其他所有点的最短距离 1->n
### 所有边全都是正数 
#### 朴素Dijkstra算法
O(n^2)(n-点数)
适合稠密图 m与n^2同级别
算法思路

s: 当前已经确定最短距离点
- 初始化距离 dis[1] = 0, dis[i] = inf
- for i in 1 ~ n: 
    t <- 在s中的最近的点
    s <- t
    用t更新其它点的距离
    dis[x] > dis[t] + w
``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int n, m;
// g - 存储图, dis - 存储各个点到起点的距离, st - 是否访问过
int g[N][N];
int dist[N];
bool st[N];

int dijkstra(){
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++){
        int t = -1;
        
        // 在所有st所有为false的点中找出距离最小的点
        for(int j = 1; j <= n; j++)
            // !st[j] 未确定最短路
            // dist[t] > dist[j] 当前不是最短
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 将t加到集合中
        st[t] = true;
        for(int j = 1; j <= n; j++)
            // 用1~t加上t到j距离 更新 1到j的距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1; // 不连通
    return dist[n];
}

int main(){
    // n - 点数, m - 边数
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof g);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); // 处理重边
    }
    
    printf("%d\n", dijkstra());
    
    return 0;
}
```
#### 堆优化版的Dijkstra算法
O(mlogn)(n-点数, m-边数)
适合稀疏图
### 存在负权边
#### Bellman-Ford
O(mn)
#### SPFA
一般O(m) 最坏O(nm)
## 多源汇最短路
多个起点
源点 -> 起点
汇点 -> 终点
### Floyd算法 
O(n^3)

