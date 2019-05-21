## Quick Sort -- Divide and Conquer
1. 确定分界点 q[l] q[h+r >> 1] 
2. ※调整区间
3. 递归处理左右两端

### 实现

- 暴力算法
```
1. a[] b[]
2. q[l~r] -- q[i] <= x x->a[]
          -- q[i] > x  x->b[] 
3. a[] -> q[], b[] -> q[]

```

- 算法模板

https://www.acwing.com/problem/content/787/

``` C++
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r){
  if(l>=r) return;
  int x = q[l], i = l - 1, j = r + 1;
  while(i < j){
    do i++ while(q[i] < x);
    do j++ while(q[j] > x);
    if(i < j) swap(q[i], q[j]);
  }
  quick_sort(q, l, j);
  quick_sort(q, j+1, r);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &q[i]);
  quick_sort(q, 0, n-1);
  for(int i = 0; i < n; i++) printf("%d ", q[i]);
  return 0;
}

```

## Merge Sort -- Divide and Conquer
https://www.acwing.com/problem/content/789/
1. 确定分界点 mid = (l+r)/2
2. 递归排序left, right
3. ※归并 -- 合二为一

``` C++
#include <iostream>
using namespace std;

int n;
const int N = 1e6+10;
int q[N], tmp[N];

void merge_sort(int q[], int l, int r){
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i<=mid && j <=r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    while(i<=mid) tmp[k++] = q[i++];
    while(j<=r) tmp[k++] = q[j++];
    for(i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}
```