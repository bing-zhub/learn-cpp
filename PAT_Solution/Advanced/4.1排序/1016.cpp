#include <bits/stdc++.h>
using namespace std;

struct record {
  string name;
  int status, month, time, day, hour, minute;
};
int rate[25], n;

double billFromZero(record call, int * rate){
  double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
  for(int i = 0; i < call.hour; i++)
    total += rate[i] * 60;
  return total / 100.0;
}

bool cmp(record a, record b) {
  return a.name != b.name ? a.name < b.name : a.time < b.time;
}

int main(){
  for(int i = 0; i < 24; i++){
    cin >> rate[i];
    rate[24] += rate[i];
  }
  cin >> n;
  vector<record> data(n);
  for(int i = 0; i < n; i++){
    cin >> data[i].name;
    scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
    string temp;
    cin >> temp;
    data[i].status = (temp=="on-line") ? 1 : 0;
    data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
  }

  sort(data.begin(), data.end(), cmp);
  map<string, vector<record>> custom;
  for(int i = 1; i < n; i++) {
    if(data[i].name == data[i-1].name && data[i - 1].status == 1 && data[i].status == 0){
      // on-line / off-line 匹配
      custom[data[i - 1].name].push_back(data[i - 1]);
      custom[data[i].name].push_back(data[i]);
    }
  }
  for(auto c: custom){
    vector<record> temp = c.second;
    cout << c.first;
    printf(" %02d\n", temp[0].month);
    double total = 0.0;
    for(int i = 1; i < temp.size(); i += 2){
      double t = billFromZero(temp[i], rate) - billFromZero(temp[i-1], rate);
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i-1].day, temp[i-1].hour, temp[i-1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i-1].time, t);
      total += t;
    }
    printf("Total amount: $%.2f\n", total);
  }
  return 0;
}