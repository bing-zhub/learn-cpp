// 有bug 懒得调了... 

#include <iostream>
using namespace std;

bool st[128];

int main(){
  string a, b;
  getline(cin, a);
  cin >> b;
  for(int i = 0; i < b.size(); i++)
    st[b[i]] = true;
  for(int i = 0; i < a.size(); i++){
    if(st[a[i]]) continue;
    printf("%c", a[i]);
  }
  return 0;
}