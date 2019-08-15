#include <iostream>
#include <algorithm>
using namespace std;

const int N = 510;
int cap, dis, avr, ns;
double nowPrice, nowDis, maxDis, totalPrice, leftDis;
struct station {
  double price; int dis;
} ss[N];

bool cmp(station a, station b){
  return a.dis < b.dis;
}

int main(){
  cin >> cap >> dis >> avr >> ns;
  for(int i = 0; i < ns; i++){
    cin >> ss[i].price >> ss[i].dis;
  }
  sort(ss, ss+ns, cmp);
  
  if(ss[0].dis != 0){
    cout << "The maximum travel distance = 0.00";
    return 0;
  }

  nowPrice = ss[0].price;

  while(nowDis < dis){
    maxDis = nowDis + cap * avr;
    double minPriceDis = 0, minPrice = 0x3f3f3f3f;
    int flag = 0;
    for(int i = 1; i <= ns && ss[i].dis <= maxDis; i++){
      if(ss[i].dis <= nowDis) continue;
      if(ss[i].price < nowPrice) {
        totalPrice += (ss[i].dis - nowDis - leftDis) * nowPrice / avr;
      }
    }
  }

  return 0;
}