#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int M = 1e6 + 10;
int n, m, flag;
struct node {
  int id, best;
  int score[4], rank[4];
} stu[N];
char _map[5] = "ACME";
bool st[M];

bool cmp(node a, node b) { return a.score[flag] > b.score[flag]; }

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int id, c, m, e, a;
    cin >> id >> c >> m >> e;
    st[id] = true;
    stu[i].id = id;
    stu[i].score[1] = c;
    stu[i].score[2] = m;
    stu[i].score[3] = e;
    stu[i].score[0] = (c + m + e ) * 1.0 / 3 + 0.5;
  }

  for(flag = 0; flag < 4; flag ++){
    sort(stu, stu+n, cmp);
    stu[0].rank[flag] = 1;
    for(int i = 1; i < n; i++){
      stu[i].rank[flag] = i + 1;
      if(stu[i].score[flag] == stu[i-1].score[flag])
        stu[i].rank[flag] = stu[i-1].rank[flag];
    }
  }

  for(int i = 0; i < n; i++){
    int best = 0x3f3f3f3f;
    for(int j = 0; j < 4; j++){
      if(stu[i].rank[j] < best){
        stu[i].best = j;
        best = stu[i].rank[j];
      }
    }
  }

  // cout << endl;
  // for(int i = 0; i < n; i++){
  //   cout << stu[i].id << ": ";
  //   for(int j = 0; j < 4; j++){
  //     cout << stu[i].score[j] << " " << stu[i].rank[j] << "; ";
  //   }
  //   cout << stu[i].best <<  endl;
  // }



  while(m--){
    int id;
    cin >> id;
    if(!st[id]) cout << "N/A" << endl;
    else{
      for(int i = 0; i < n; i++){
        if(stu[i].id == id){
          cout << stu[i].rank[stu[i].best] << " " << _map[stu[i].best] <<  endl;
        }
      }
    }
  }
  return 0;
}