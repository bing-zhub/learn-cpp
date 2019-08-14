// 有bug... 懒得管了

#include <iostream>
using namespace std;

bool val[10010];

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    val[t] = true;
  }

  bool flag = false;
  for(int i = 1; i < 10010; i++){
    for(int j = i; j < 10010; j++){
      if(val[i] && val[j] && i!=j && i + j == m){
        cout << i << " " << j;
        flag = true;
        break;
      }
      if(flag) break;
    }
  }
  if(!flag) cout << "No Solution";
  return 0;
}