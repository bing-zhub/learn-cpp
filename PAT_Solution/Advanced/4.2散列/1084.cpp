// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//   string a, b, res;
//   cin >> a >> b;
//   for(int i = 0; i < a.size(); i++){
//     // string.find(sub_string) 不存在返回 string::npos(-1) 
//     if(b.find(a[i]) == -1 && res.find(toupper(a[i]))== -1){
//       res += toupper(a[i]);
//     }
//   }
//   cout << res;
//   return 0;
// }

#include <iostream>
using namespace std;

string s1, s2;
bool shown[128];

int main(){
  cin >> s1 >> s2;
  for(int i = 0; i < s1.size(); i++){
    char t1 = s1[i], t2;
    int j;
    if(t1 >= 'a' && t1 <= 'z') t1 -= 32;
    for(j = 0; j < s2.size(); j++){
      t2 = s2[j];
      if(t2 >= 'a' && t2 <= 'z') t2 -= 32;
      if(t2==t1) break;
    }
    if(j==s2.size() && !shown[t1]){
      printf("%c", t1);
      shown[t1] = true;
    }
  }
  return 0;
}