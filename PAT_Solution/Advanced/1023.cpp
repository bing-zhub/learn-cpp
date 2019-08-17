// 好好读题 题目中说无论是否符合条件都要输出*2后的数字

#include <iostream>
#include <vector>
using namespace std;

int _hashA[110], _hashB[110];

vector<int> dou(vector<int> &a) {
  vector<int> c;
  int t = 0; // 进位
  for (int i = 0; i < a.size() || t; i++) {
    if (i < a.size())
      t += a[i] * 2;
    c.push_back(t % 10);
    _hashB[t % 10]++;
    t /= 10;
  }
  return c;
}

int main() {
  string s;
  vector<int> a;
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--)
    _hashA[s[i]-'0']++, a.push_back(s[i] - '0');
  auto c = dou(a);
  bool flag = true;
  for (int i = 0; i < 110; i++) {
    if (_hashA[i] != _hashB[i]) {
      flag = false;
      break;
    }
  }
  if(!flag) cout << "No" << endl;
  else
    cout << "Yes" << endl;
  for(int i = c.size() - 1; i >= 0; i -- ) cout << c[i];
  
  return 0;
}