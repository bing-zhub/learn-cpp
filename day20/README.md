

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
## 广度优先搜索 BFS
数据结构: 队列
空间O(2^h)
最短路
## 树与图的存储

## 树与图的深度优先遍历

## 树与图的广度优先遍历

## 拓扑排序