#include <iostream>
#include <algorithm>
using namespace std;

string str[10010];
int n;

bool cmp(string a, string b){
  return a + b < b + a;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> str[i];
  sort(str, str+n, cmp);
  string t;
  for(int i = 0; i < n; i++) t += str[i];
  while(t.size() != 0 && t[0] == '0') t.erase(t.begin());

  if(t.size() == 0) cout << "0";
  else cout << t;
  return 0;
}