#include <bits/stdc++.h>
using namespace std;

string str;
int steps;

void _add(string t){
  int c = 0;
  for(int i = 0; i < t.size(); i++){
    str[i] = str[i] + t[i] + c - '0';
    c = 0;
    if(str[i]>'9'){
      str[i] -= 10;
      c = 1;
    }
  }
  if(c) str+= '1';
  reverse(str.begin(), str.end());
}

int main(){
  cin >> str >> steps;
  int i;
  for(i = 0; i <= steps; i++){
    string t = str;
    reverse(t.begin(), t.end());
    if(str==t || i == steps) break;
    _add(t);
  }
  cout << str << endl << i;
  return 0;
}