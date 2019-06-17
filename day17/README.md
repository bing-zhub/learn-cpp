## Trie树
高效地存储和查找字符串集合的数据结构
[Trie树](https://www.acwing.com/problem/content/837/)
``` C++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

// 下标是0的点, 即是根节点, 又是空节点
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[]){
  int p = 0;
  for(int i = 0; str[i]; i++){
    int u = str[i] - 'a'; // 映射到0~25
    if(!son[p][u]) son[p][u] = ++ idx;
    p = son[p][u];
  }

  cnt[p] ++;
}

int query(char str[]){
  int p = 0;
  for(int i = 0; str[i]; i++){
    int u = str[i] - 'a';
    if(!son[p][u]) return 0;
    p = son[p][u];
  }
  return cnt[p];
}

int main(){
  int n;
  scanf("%d", &n);
  while(n--){
    char op[2];
    scanf("%s%s", op, str);
    if(op[0] == 'I') insert(str);
    else printf("%d\n", query(str));
  }
  return 0;
}
```

## 并查集
近乎O(1)
1. 将两个集合合并
2. 询问两个元素是否在一个集合当中

基本原理: 每个集合用一棵树来表示. 树根的编号就是整个集合的编号. 每个节点存储它的父节点. p[x]表示x的父节点  

1. 如何判断树根
if(p[x] = x)
2. 如何求x的集合编号
while(p[x] != x) x = p[x];
3. 如何合并两个集合
px是x的集合编号 py是y的集合编号 
p[x] = y

优化
1. 路径压缩

[合并集合](https://www.acwing.com/problem/content/838/)
``` C++
#include <iostream>
using namespace std;

int n,m;
const int N = 1e6 + 10;
int p[N];

int find(int x){ // 返回x的祖宗节点 + 路径压缩
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++) p[i] = i;
  while(m--){
    // 防止读回车等
    char op[2];
    int a,b;
    scanf("%s%d%d", op, &a, &b);
    if(op[0] == 'M') p[find(a)] = find(b);
    else{
      if(find(a) == find(b)) puts("Yes");
      else puts("No");
    }
  }
}
```
( 连通块中点的数量)[https://www.acwing.com/problem/content/839/]

``` C++
#include <iostream>
using namespace std;

int n,m;
const int N = 1e6 + 10;
int p[N], _size[N];

int find(int x){ // 返回x的祖宗节点 + 路径压缩
  if(p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 1; i<=n; i++){
    p[i] = i;
    _size[i] = 1;
  }
  while(m--){
    // 防止读回车等
    char op[5];
    int a,b;
    scanf("%s", op);
    if(op[0] == 'C'){
      scanf("%d%d", &a, &b);
      // 如果已经在一个集合 无需重复合并
      if(find(a) == find(b)) continue;
      _size[find(b)] += _size[find(a)];
      p[find(a)] = find(b);
    } else if(op[1] == '1') {
      scanf("%d%d", &a, &b);
      if(find(a) == find(b)) puts("Yes");
      else puts("No");
    } else {
      scanf("%d", &a);
      printf("%d\n", _size[find(a)]);
    }
  }
}
```

## 堆

手写堆

小根堆 -- 每个点小于左右子节点 -- 堆顶是最小值

存储 
x为根 左节点 2x 右节点 2x+1

基础操作
1. 向下调整 - down(x)
2. 向上调整 - up(x)

可以由基础操作组合
1. 插入一个数 - heap[++ size] = x; up(size);
2. 求集合中的最小值 - heap[1];
3. 删除集合中的最小值 - heap[1] = heap[size--]; down(1); 
4. 删除任意一个元素 - heap[k] = heap[size--]; down(k); up(k);
5. 修改任意一个元素 - heap[k] = x; down(k);

[堆排序](https://www.acwing.com/problem/content/840/)

``` C++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int n,m;
int h[N], size;

void down(int u){
    int t = u;
    // 左节点存在且小于父节点 则指向左节点
    if(u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    // 右节点存在且小于父节点 则指向右节点
    if(u * 2 + 1 <= size && h[u*2+1] < h[t]) t = u * 2 + 1;
    if(u!=t){
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u){
    while(u / 2 && h[u / 2] > h[u]){
        swap(h[u / 2], h[u]);
        u / 2;
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
    size = n;
    
    for(int i = n/2; i >=1; i--) down(i);
    
    while(m--){
        printf("%d ", h[1]);
        h[1] = h[size];
        size --;
        down(1);
    }
}
```

[模拟堆](https://www.acwing.com/problem/content/841/)

``` C++

```