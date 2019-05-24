// 793

#include <iostream>
#include <vector>

using namespace std;

// A>=B
bool cmp(vector<int> &a, vector<int> &b){
  if(a.size() != b.size()) return a.size() > b.size();
  else{
    for(int i = a.size() - 1; i >= 0; i--)
      if(a[i] != b[i]) return a[i] > b[i];
  }
  return true;
}

// 加引用会提高效率 不加引用会复制一份
// C = A + B
vector<int> add(vector<int> &a, vector<int> &b){
  vector<int> c;
  int t = 0;
  for(int i = 0; i < a.size() || i < b.size(); i++){
    if(i < a.size()) t += a[i];
    if(i < b.size()) t += b[i];
    c.push_back(t % 10);
    t /= 10;
  }
  if(t) c.push_back(1);
  return c;
}

vector<int> sub(vector<int> a, vector<int> b){
  vector<int> c;
  for(int i = 0, t = 0; i < a.size(); i++){
    t = a[i] - t;
    if(i < b.size()) t -= b[i];
    c.push_back((t+10)%10);
    if(t < 0) t = 1;
    else t = 0; 
  }

  while(c.size() > 1 && c.back() == 0) c.pop_back(); // 去掉前导0
  return c;
}

int main(){
  string a, b;
  vector<int> A,B;

  cin >> a >> b; // a = "123456"
  for(int i = a.size() - 1; i>=0; i--) A.push_back(a[i] - '0'); // a = {6,5,4,3,2,1}
  for(int i = b.size() - 1; i>=0; i--) B.push_back(b[i] - '0');

  auto C = add(A, B);

  for(int i = C.size() - 1; i >=0 ; i--) printf("%d", C[i]);
  cout << endl;
  if(cmp(A, B)){
    auto C = sub(A,B);
    for(int i = C.size() - 1; i >=0 ; i--) printf("%d", C[i]);
  } else {
    auto C = sub(B,A);
    for(int i = C.size() - 1; i >=0 ; i--) printf("%d", C[i]);
  }

  return 0;
}
