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

1. 插入一个数
2. 求集合当中的最小值
3. 删除最小值
4. 删除任意一个元素
5. 修改任意一个元素

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


[模拟堆](https://www.acwing.com/problem/content/description/841/)

``` C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int hp[N], ph[N];
int h[N];
int size;

// “I x”，插入一个数x；
// “PM”，输出当前集合中的最小值；
// “DM”，删除当前集合中的最小值（当最小值不唯一时，删除最早插入的最小值）；
// “D k”，删除第k个插入的数；
// “C k x”，修改第k个插入的数，将其变为x；

void heap_swap(int u, int v)
{
    swap(ph[hp[u]], ph[hp[v]]);
    swap(hp[u], hp[v]);
    swap(h[u], h[v]);
}

void down(int u)
{
    int t = u;
    if (2*u <= size && h[2*u] < h[t]) t = 2*u;
    if (2*u+1 <= size && h[2*u+1] < h[t]) t = 2*u+1;
    if (t != u)
    {
        heap_swap(t, u);
        down(t);
    }
}

void up(int u)
{
    while (u/2 && h[u] < h[u/2])
    {
        heap_swap(u, u/2);
        u >>= 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    char op[3];
    int a, b;
    int m = 0;
    while (n--)
    {
        scanf("%s", op);
        if (!strcmp(op, "I")) 
        {
            scanf("%d", &a);
            m++;
            h[++size] = a, ph[m] = size, hp[size] = m;
            up(size);
        }
        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
        else if (!strcmp(op, "DM")) 
        {
            heap_swap(1, size);
            size--;
            down(1);
        }
        else if (!strcmp(op, "D")) 
        {
            scanf("%d", &a);
            int u = ph[a];
            heap_swap(u, size);
            size--;
            up(u), down(u);
        }
        else
        {
            scanf("%d%d", &a, &b);
            int u = ph[a];
            h[u] = b;
            up(u), down(u);
        }
    }
    return 0;
}
```