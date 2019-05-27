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


##