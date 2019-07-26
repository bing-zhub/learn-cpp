#include <iostream>
using namespace std;

const int N = 2010;
double poly[N], res[N];
int n, m;

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int a; double b;
    scanf("%d%lf", &a, &b);
    poly[a] = b;
  }

  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    int a; double b;
    scanf("%d%lf", &a, &b);
    for(int i = 0; i < N; i++){
      res[a+i] += poly[i]*b;
    }
  }

  int count = 0;
  for(int i = N-1; i >= 0; i--) if(res[i]!=0.0) count ++;
  printf("%d", count);
  for(int i = N-1; i >= 0; i--){
    if(res[i]!=0.0){
      printf(" %d %.1f", i, res[i]);
    }
  }
  return 0;
}