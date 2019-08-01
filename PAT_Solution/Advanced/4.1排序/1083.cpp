#include <bits/stdc++.h>
using namespace std;

int n, l, h;

struct node {
  string name, course;
  int score;
}; 

vector<node> data, res;

bool cmp(node a, node b){
  return a.score > b.score;
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    node t;
    cin >> t.name >> t.course >> t.score;
    data.push_back(t);
  }
  sort(data.begin(), data.end(), cmp);
  cin >> l >> h;
  for(auto c: data){
    if(c.score >= l && c.score <= h){
      res.push_back(c);
    }
  }
  if(res.size() == 0){
    cout << "NONE";
  }else{
    for(auto c: res){
      cout <<  c.name << " " << c.course << endl;
    }
  }
  return 0;
}