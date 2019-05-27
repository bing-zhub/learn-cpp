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