#include <iostream>
using namespace std;

typedef long long ll;
ll a, b, c;
int n;

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a >> b >> c;
    printf("Case #%d: ", i);
    if(b>c-a) puts("true");
    else puts("false");
  }
  return 0;
}