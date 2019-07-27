#include <bits/stdc++.h>
using namespace std;

struct node {
  int id, de, cai;
};

int n, l, h, cnt;
vector<node> v[4]; 

bool cmp(node a, node b){
  if((a.de + a.cai) != (b.de + b.cai))
    return (a.de + a.cai) > (b.de + b.cai);
  else if(a.de != b.de)
    return a.de > b.de;
  else
    return a.id < b.id;
}

int main(){
  scanf("%d%d%d", &n, &l, &h);
  while(n--){
    node p;
    cin >> p.id >> p.de >> p.cai;
    if(p.de >= l && p.cai >= l){
      cnt ++;
      if(p.de >= h && p.cai >= h) v[0].push_back(p);
      else if(p.de >= h && p.cai < h) v[1].push_back(p);
      else if(p.de < h && p.cai < h && p.de >= p.cai) v[2].push_back(p);
      else v[3].push_back(p);
    }
  }
  cout << cnt;
  for(int i = 0; i < 4; i++){
    sort(v[i].begin(), v[i].end(), cmp);
    for(int j = 0; j < v[i].size(); j++){
      node t =  v[i][j];
      cout << "\n" << t.id << " " << t.de << " " << t.cai;
    }
  }

  return 0;
}