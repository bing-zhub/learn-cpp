#include <bits/stdc++.h>
using namespace std;

int main(){
  string a, b, res;
  cin >> a >> b;
  for(int i = 0; i < a.size(); i++){
    // string.find(sub_string) 不存在返回 string::npos(-1) 
    if(b.find(a[i]) == -1 && res.find(toupper(a[i]))== -1){
      res += toupper(a[i]);
    }
  }
  cout << res;
  return 0;
}