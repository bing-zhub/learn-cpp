## 深度优先搜索 DFS
数据结构: 栈
空间: O(h)
不具有最短性
[排列数字](https://www.acwing.com/problem/content/844/)
``` C++
#include <iostream>
using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u){
    if(u == n) {
        for(int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!st[i]){
            path[u] = i;
            st[i] = true;
            dfs(u + 1);
            // 恢复现场
            st[i] = false;
        }
    }
}

int main(){
    scanf("%d", &n);
    dfs(0);
    return 0;
}
```

[n-皇后问题](https://www.acwing.com/problem/content/845/)
``` C++
#include <iostream>

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u){
    if(u == n){
        for(int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }
    
    for(int i = 0; i < n; i++){
        if(!col[i] && !dg[u + i] && !udg[n - u + i]){
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = false;
            g[u][i] = '.';
        }
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
```
## 广度优先搜索 BFS
数据结构: 队列
空间O(2^h)
最短路
[走迷宫](https://www.acwing.com/problem/content/846/)
``` c++
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

int n, m;
const int N = 110;

int d[N][N], g[N][N];
// 记录路径
PII Prev[N][N];

int bfs(){
    queue<PII> q;
    
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++){
            int x = t.first + dx[i], y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0){
                d[x][y] = d[t.first][t.second] + 1;
                // 记录路径
                Prev[x][y] = t;
                q.push({x, y});
            }
        }
    }

    // 记录路径    
    // for(int x = n -1, y = m - 1; x || y;){
    //     cout << x << ' ' << y << ' ' << endl;
    //     auto t = Prev[x][y];
    //     x = t.first;
    //     y = t.second;
    // }
    
    return d[n-1][m-1];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
            
    cout << bfs() << endl;
    return 0;
}
```
## 树与图的存储
树是一种五环连通图

图:
1. 有向图
2. 无向图
--- 
存储
1. 邻接矩阵
 O(n^2)  `g[a][b]` 存储a->b的信息 不存储重边 比较适合稠密图
2. 邻接表
每个点一个单链表, 存储可以到达的节点

[树的重心](https://www.acwing.com/problem/content/848/)
``` C++
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10, M = N * 2;

int n, ans = N;
// h -> 链表头, e -> 节点值, ne -> 每个节点next指针, idx -> 当前操作位置 
int h[N], e[M], ne[M], idx;
bool st[N];
// 插入 a -> b 的边
void add(int a, int b) {
    // 创建节点 
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

// u -> 当前遍历到u节点
int dfs(int u){
    st[u] = true;
    int sum = 1, res =  0;
    for(int i = h[u]; i!= -1; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            int s =  dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1);
    cout << ans << endl;
}
```
## 树与图的深度优先遍历

## 树与图的广度优先遍历

## 拓扑排序