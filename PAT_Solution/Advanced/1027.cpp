#include <iostream>
using namespace std;
char map[14] = {"0123456789ABC"};

int main(){
    printf("#");
    for(int i = 0; i < 3; i++){
        int t;
        scanf("%d", &t);
        printf("%c%c", map[t/13], map[t%13]);
  }
  return 0;
}