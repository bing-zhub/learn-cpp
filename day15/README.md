## 双指针

1. 一个开头 一个结尾
2. 一个开头 一个中间(划分为两部分)

### 模板

``` C++
for(i = 0, j = 0; i < n; i++){
  while(j < i && check(i, j)) j++;

  // 每道题具体逻辑
}
```

### 核心思想
``` C++
for(int i = 0; i < n; i++)
  for(int j = 0; j < n; j++)
    o(n^2)
```
将上面BF算法优化到O(n)

### 例子

1. 将空格分割的单词提取出来

``` C++
#include <iostream>
#include <string.h>
using namespace std;

int main(){
  char str[1000];
  gets(str);
  int n = strlen(str);
  for(int i =0; i < n; i++){
    int j = i;
    while( j < n && str[j] != ' ') j++;
    for(int k = i; k < j; k++) cout << str[k];
    cout << endl;
    i = j;
  }
  return 0;
}

```

2. 最长连续不重复子序列

[最长连续不重复子序列](https://www.acwing.com/problem/content/801/)

朴素 O(n^2)

``` C++
for(int i = 0; i < n; i++)
  for(int j = 0; j <= i; j++)
    if(check(j, i)){
      res = max(res, i - j + 1);
    }
```

双指针 O(n)

``` C++
for(int i = 0, j = 0; i < n; i++){
  // j 往左最远到哪里
  while(j<=i && check(j, i)) j++;

  res = max(res, i - j + 1);
}
```

Code 

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

int n;
const int N = 1e6 + 10;

// a 读入序列
// s 区间数列 出现次数 
int a[N], s[N];

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  for(int i = 0, j = 0; i < n; i++){
    // 放入区间数列
    s[a[i]] ++;

    // 出现重复 j后移 并把这个数移出区间数列
    while(s[a[i]] > 1){
      s[a[j]] -- ;
      j ++;
    }
    res = max(res, i - j + 1);
  }
  cout << res; 
}
```


## 位运算

### n的二进制表示中第K位是几

n = 15 = (1111)2
1. 先把第K位移到最后 `>>k`
2. 看下个位是几 `x&1`

`n >> k & 1`

### 返回x的最后一位1
[803]()
二进制表示中共有多少个1

x = 1010
lowbit(x) = 10

x = 101000
lowbit(x) = 1000

`x&-x` = `x&(~x+1)`


``` C++
#include <iostream>
using namespace std;

int lowbit(int x){
  return x&-x;
}

int main(){
  int n;
  cin >> n;
  while(n --) {
    int x;
    cin >> x;
    int res = 0;
    while(x) x-=lowbit(x), res++;
    cout << res << " ";
  }
}
```

## 离散
804
``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

const int N = 3e6+10;

int n, m;
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x){
  int l = 0, r = alls.size() - 1;
  while(l < r) {
    int mid = l + r >> 1;
    if(alls[mid] >= x) r = mid;
    else l = mid + 1;
  }
  return r + 1;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int x,c;
    cin >> x >> c;
    // 以pair形式读入所有操作数
    add.push_back({x,c});
    alls.push_back(x);
  }
  for(int i = 0; i < m; i++){
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});

    alls.push_back(l);
    alls.push_back(r);
  }


  // 去重
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  // alls剩下都是不重复的

  // 把add离散化到a 处理插入
  for(auto item:add){
    int x = find(item.first);
    a[x] += item.second;
  }


  for(int i = 1; i <= alls.size(); i++) s[i] = s[i -1] + a[i];
  for(auto item:query){
    int l = find(item.first) , r = find(item.second);
    cout << s[r] - s[l-1] << endl;
  }
  return 0;
}
```

## 区间合并
1. 按照区间左端点排序
2. 扫描整个区间, 把可能有交集区间进行合并
``` C++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n;
vector<PII> segs;

void merge(vector<PII> &segs){
  vector<PII> res;
  sort(segs.begin(), segs.end());

  int st = -2e9, ed = -2e9;
  for(auto seg: segs)
    if(ed< seg.first){
      if(st != -2e9) res.push_back({st, ed});
      st = seg.first, ed = seg.second;
    }else {
      ed = max(ed, seg.second);
    }
  
  if(st != -2e9) res.push_back({st, ed});

  segs = res;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    int l, r;
    cin >> l >> r;
    segs.push_back({l, r});
  }

  merge(segs);

  cout << segs.size() << endl;

  return 0;
}
```