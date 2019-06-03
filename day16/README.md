# 链表与邻接表
new Node(); 非常慢....
## 单链表
[单链表](https://www.acwing.com/problem/content/828/)
``` C++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

// e => 节点的值
// ne => 下个节点下标
// idx => 存储当前已经用到了哪个点 
int head, e[N], ne[N], idx;

void init(){
  head = -1;
  idx = 0;
}

// 插到头结点
void add_to_head(int x){
  e[idx] = x, ne[idx] = head, head = idx ++;
}

// 将x插到是k后面
void add(int k, int x){
  e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
}

void remove(int k){
  ne[k] = ne[ne[k]];
}

int main(){
  init();
  int m;
  cin >> m;
  while(m--){
    int k, x;
    char op;
    cin >> op;
    if(op == 'H'){
      cin >> x;
      add_to_head(x);
    }else if(op == 'D'){
      cin >> k;
      if(!k) head = ne[head];
      else remove(k-1);
    }else{
      cin >> k >> x;
      add(k-1, x);
    }
  }

  for(int i = head; i!=-1; i = ne[i]) cout << e[i] << " ";
  cout << endl;
  return 0;
}
```

### 邻接表
许多个单链表
存储图和树
## 双链表
优化某些问题
``` C++
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int m;
int e[N], l[N], r[N], idx;

void init(){
  // 0左端点 1右端点
  r[0] = 1;
  l[1] = 0;
  idx = 2;
}

// 在下标为k的右边插入x
void add(int k, int x){
  e[idx] = x;
  r[idx] = r[k];
  l[idx] = k;
  l[r[k]] = idx;
  r[k] = idx;
}

// 删除第K个点
void remove(int k){
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

void add_left(int k, int x){
  add(l[k], x);
}

int main(){
  init();
  return 0;
}
```

# 栈与队列
## 单调栈
[单调栈](https://www.acwing.com/problem/content/832/)
``` C++
#include <iostream>
using namespace std;

const int N = 1e6+10;

int n;
int stk[N], tt;

int main(){
  cin >> n;
  for(int i = 0;i < n; i++){
    int x; 
    cin >> x;
    while(tt && stk[tt] >= x) tt --;
    if(tt) cout << stk[tt] << ' ';
    else cout << -1 << ' ';
    stk[++ tt] = x;
  }
  return 0;
}
```
## 单调队列
[滑动窗口](https://www.acwing.com/problem/content/156/)
``` C++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main(){
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  
  int hh = 0, tt = -1;
  for(int i = 0; i < n; i++){
    // 判断队头是否滑出窗口
    if(hh <= tt && i-k+1> q[hh]) hh++;
    while(hh <= tt && a[q[tt]] >= a[i]) tt --;

    q[++ tt] = i;
    if(i>= k -1) printf("%d ", a[q[hh]]);
  }
  puts("");
  
  hh = 0, tt = -1;
  for(int i = 0; i < n; i++){
    // 判断队头是否滑出窗口
    if(hh <= tt && i-k+1> q[hh]) hh++;
    while(hh <= tt && a[q[tt]] <= a[i]) tt --;

    q[++ tt] = i;
    if(i>= k -1) printf("%d ", a[q[hh]]);
  }
  puts("");
  return 0;
}
```
[注] scanf会比cin快很多
# KMP

朴素做法
``` C++
int S[N], p[M];
for(int i = 1; i <= n; i++){
  bool flag = true;
  for(int j = 1; j <= m; j++){
    if(s[i]!=[[j]]){
      flag = false;
      break;
    }
  }
}
```

kmp
``` C++
#include <iostream>

using namespace std;

const int N = 10010, M = 100010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;

    for (int i = 2, j = 0; i <= n; i ++ )
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}

```