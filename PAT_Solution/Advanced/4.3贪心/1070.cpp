// 有bug ... 懒得调

#include <iostream>
#include <algorithm>
using namespace std;

int kinds, demand;
const int N = 1010;
struct cake {
  int tons;
  double per, total;
} cakes[N];
double res;

bool cmp(cake a, cake b){
  return a.per > b.per;
}

int main(){
  cin >> kinds >> demand;
  for(int i = 0; i < kinds; i++) cin >> cakes[i].tons;
  for(int i = 0; i < kinds; i++) cin >> cakes[i].total, cakes[i].per = cakes[i].total / cakes[i].tons;
  sort(cakes, cakes+kinds, cmp);
  for(int i = 0; i < kinds; i++){
    if(demand - cakes[i].tons > 0)
      demand -= cakes[i].tons, res+= cakes[i].total;
    else{
      res += cakes[i].per * demand;
      break;
    }
  }
  printf("%.2f", res);
  return 0;
}