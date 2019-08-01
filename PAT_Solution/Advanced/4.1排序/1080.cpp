#include <bits/stdc++.h>
using namespace std;

int n, m, k, quota[110], cnt[110];

struct node {
  int id, ge, gi, fin;
  vector<int> choice;
};

bool cmp(node &a, node &b){
  if(a.fin != b.fin)
    return a.fin > b.fin;
  else
    return a.ge > b.ge;
}

bool cmp1(node &a, node &b){
  return a.id < b.id;
}

int main(){
  scanf("%d%d%d", &n, &m, &k);
  vector<node> stu(n), sch[110];
  for(int i = 0; i < m; i++) scanf("%d", &quota[i]);
  for(int i = 0; i < n; i++) {
    scanf("%d%d", &stu[i].ge, &stu[i].gi);
    stu[i].id = i;
    stu[i].fin = stu[i].ge + stu[i].gi;
    stu[i].choice.resize(k);
    for(int j = 0; j < k; j++) scanf("%d", &stu[i].choice[j]);
  }
  sort(stu.begin(), stu.end(), cmp);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      int schid = stu[i].choice[j];
      int lastIndex = cnt[schid] - 1;
      if(cnt[schid] < quota[schid] || (stu[i].fin == sch[schid][lastIndex].fin && stu[i].ge == sch[schid][lastIndex].ge)){
        sch[schid].push_back(stu[i]);
        cnt[schid]++;
        break;
      }
    }
  }
  for(int i = 0; i < m; i++){
    sort(sch[i].begin(), sch[i].end(), cmp1);
    for(int j = 0; j < sch[i].size(); j++){
      if(j!=0) printf(" ");
      printf("%d", sch[i][j].id);
    }
    printf("\n");
  }
  return 0;
}