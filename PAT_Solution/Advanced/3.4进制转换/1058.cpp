#include <iostream>
using namespace std;
int ga, sa, ka;

int main(){
  for(int i = 0; i < 2; i++){
    int g, s, k;
    scanf("%d.%d.%d", &g, &s, &k);
    sa += s;
    ka += k;
    ga += g;
  }
  if(ka>28) sa ++, ka -=29;
  if(sa>16) ga ++ , sa -=17;
  printf("%d.%d.%d", ga, sa, ka);
  return 0;
}