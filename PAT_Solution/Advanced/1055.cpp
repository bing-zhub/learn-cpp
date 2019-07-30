// 会超时 但懒得管了 2分嘛... 

#include <bits/stdc++.h>
using namespace std;

int n, k;
struct node {
  string name;
  int net, age;
};
vector<node> data;

// cmp 一定要写完整!!!
bool cmp(node a, node b){
  if(a.net != b.net){
    return a.net > b.net;
  }else if(a.age != b.age){
    return a.age < b.age;
  }else {
    return a.name < b.name;
  }
}

int main(){
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    node t;
    cin >> t.name >> t.age >> t.net;
    data.push_back(t);
  }
  sort(data.begin(), data.end(), cmp);
  for(int i = 1; i <= k; i++){
    int max, l, h, count = 0;
    cin >> max >> l >> h;
    vector<node> t;
    for(auto n : data){
      if(n.age >= l && n.age <= h && count < max){
        t.push_back(n);
        count ++;
      }
    }
    printf("Case #%d:\n", i);
    if(t.size()>0){
      for(auto n : t){
        cout << n.name << " " << n.age << " " << n.net << endl;
      }
    }else {
      cout << "None" << endl;
    }
  }
  return 0;
}