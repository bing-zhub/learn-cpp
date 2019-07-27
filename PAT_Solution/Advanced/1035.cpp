#include <bits/stdc++.h>
using namespace std;
vector<string> processed;
int n;

// 注意输出格式的控制 单复数. 比对答案结果
int main(){
  scanf("%d", &n);
  int t = n;
  while(n--){
    string id, pwd;
    cin >> id >> pwd;
    bool flag = false;
    for(int i = 0; i < pwd.size(); i++){
      switch(pwd[i]){
        case '1': pwd[i] = '@'; flag = true; break;
        case '0': pwd[i] = '%'; flag = true; break;
        case 'l': pwd[i] = 'L'; flag = true; break;
        case 'O': pwd[i] = 'o'; flag = true; break;
      }
    }
    if(flag) processed.push_back(id + " " + pwd);
  }

  if(processed.size()!=0){
    cout << processed.size();
    for(auto c: processed) cout << endl <<  c;
  }else if(t>1)
    cout << "There are " << t << " accounts and no account is modified";
  else
    cout << "There is 1 account and no account is modified";
  return 0;
}