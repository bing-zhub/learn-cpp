#include <iostream>
using namespace std;
double ans = 1.0;
char map[3] = {'W', 'T', 'L'};

int main(){
  for(int i = 0; i < 3; i++){
    int max_idx = -1; double max = 0;
    for(int j = 0; j < 3; j++){
      double t;
      scanf("%lf", &t);
      if(t > max) max = t, max_idx = j;
    }
    ans *= max;
    printf("%c ", map[max_idx]);
  }
  printf("%.2f", (ans * 0.65 - 1) * 2);
  return 0;
}