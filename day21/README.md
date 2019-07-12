





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

[Dijkstra求最短路](https://www.acwing.com/problem/content/851/)
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
    dist[1] = 0;
    for(int i = 0; i < n; i++){
        int t = -1; // 表示还未确定
        
        // 在所有st所有为false的点中找出距离最小的点t
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
    memset(dist, 0x3f, sizeof dist);
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
``` C++
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> PII; 

int n,m;
const int N = 1e6 + 10;
int dist[N], w[N], h[N], e[N], ne[N], idx;
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c,ne[idx] =  h[a], h[a] = idx ++;
}

int dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({0, 1});
    while(!heap.empty()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if(st[ver]) continue;
        
        for(int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > distance + w[i]){
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}
```
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
