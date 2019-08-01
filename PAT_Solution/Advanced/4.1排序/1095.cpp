#include <bits/stdc++.h>
using namespace std;

int n, q, maxtime, tempindex;

struct node {
  string id;
  int flag, time;
};

bool cmp(node &a, node &b) {
  if (a.id != b.id)
    return a.id < b.id;
  else
    return a.time < b.time;
}

bool cmp2(node &a, node &b) { return a.time < b.time; }

int main() {
  scanf("%d%d", &n, &q);
  vector<node> record(n), car;
  for (int i = 0; i < n; i++) {
    string temp;
    int h, m, s;
    cin >> record[i].id;
    scanf("%d:%d:%d", &h, &m, &s);
    cin >> temp;
    record[i].time = 3600 * h + 60 * m + s;
    record[i].flag = temp == "in" ? 1 : -1;
  }
  sort(record.begin(), record.end(), cmp);
  map<string, int> _map;
  for (int i = 0; i < n - 1; i++) {
    if (record[i].id == record[i + 1].id && record[i].flag == 1 &&
        record[i + 1].flag == -1) {
      car.push_back(record[i]);
      car.push_back(record[i + 1]);
      _map[record[i].id] += (record[i + 1].time - record[i].time);
      maxtime = max(maxtime, _map[record[i].id]);
    }
  }
  sort(car.begin(), car.end(), cmp2);
  vector<int> cnt(n);
  for (int i = 0; i < car.size(); i++) {
    if (i == 0)
      cnt[i] += car[i].flag;
    else
      cnt[i] = cnt[i - 1] + car[i].flag;
  }
  for (int i = 0; i < q; i++) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int temptime = h * 3600 + m * 60 + s;
    int j;
    for (j = tempindex; j < car.size(); j++) {
      if (car[j].time > temptime) {
        printf("%d\n", cnt[j - 1]);
        break;
      } else if (j == car.size() - 1) {
        printf("%d\n", cnt[j]);
      }
    }
    tempindex = j;
  }
  for (map<string, int>::iterator it = _map.begin(); it != _map.end(); it++) {
    if (it->second == maxtime) printf("%s ", it->first.c_str());
  }
  printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
  return 0;
}