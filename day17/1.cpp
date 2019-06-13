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
