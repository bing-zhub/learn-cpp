#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> ans;

int main(){
  scanf("%d%d", &n, &m);
  while(n>0){
    ans.push_back(n%m);
    n/=m;
  }
  vector<int> rev = ans;
  reverse(rev.begin(), rev.end());
  bool flag = true;
  for(int i = 0; i < ans.size(); i++){
    if(rev[i]!=ans[i]){
      flag = false;
      break;
    }
  }
  if(flag) puts("Yes"); else puts("No");
  cout << rev[0];
  for(int i = 1; i < rev.size(); i ++ ) cout << " " << rev[i];
  return 0;
}