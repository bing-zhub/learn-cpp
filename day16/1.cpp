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