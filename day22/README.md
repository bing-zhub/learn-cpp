![05405-vbp6uyqe2p.png](http://images.zshaopingb.cn/2019/07/3596239028.png)
## 最小生成树(无向图)
### Prim算法
#### 朴素版Prim算法 O(n^2) -- 稠密图
- dist[i] <- INF
- for(i=0; i<= n; i++) 
    t <- 集合外距离最近的点
    用t更新其他点到集合的距离
    s[t] = true;

[Prim算法求最小生成树](https://www.acwing.com/problem/content/860/)
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
- 将所有边按权重从小到大排序 O(mlogm)
- 从小到大枚举每条边 a-w-b
  a/b不连通 将这条边加入集合中 
[Kruskal算法求最小生成树](https://www.acwing.com/problem/content/861/)
``` C++
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator< (const Edge &W) const {
        return w < W.w;
    }
} edges[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m;i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }
    
    sort(edges, edges + m);
    
    for(int i = 1; i<= n; i++) p[i] = i;
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a);
        b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    
    if(cnt < n -1) puts("impossible");
    else printf("%d\n", res);
    return 0;
}
```
## 二分图 (集合内部没有边)
二分图当且仅当图中不含奇数环
### 如何判别 -- 染色法 -- O(n+m)
- for(i=1;i<=n;i++)
    if i未染色:
    dfs(i, 1)
[染色法判定二分图](https://www.acwing.com/problem/content/862/)
``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c){
    color[u] = c;
    for(int i = h[u]; i!=-1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, 3 - c)) return false;
        }else if(color[j] == c) {
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }
    
    bool flag = true;
    for(int i = 1; i <= n; i++){
        if(!color[i]){
            if(!dfs(i, 1)){
                flag = false;
                break;
            }
        }
    }
    
    if(flag) puts("Yes");
    else puts("No");
    
    return 0;
}
```
### 匈牙利算法 -- 二分图的最大匹配 -- O(mn)
[二分图的最大匹配](https://www.acwing.com/problem/content/863/)
``` C++
#include <cstring>
#include <iostream>
using namespace std;

const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int e[M], ne[M], h[N], idx;
bool st[N];
int match[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x){
    for (int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]){           
            st[j] = true;
            if (!match[j] || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d%d", &n1, &n2, &m); 
    memset(h, -1, sizeof h);
    while (m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++){
        memset(st, false, sizeof st);
        if (find(i)) res++;
    }
    printf("%d\n", res);
}
```