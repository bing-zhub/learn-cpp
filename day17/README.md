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