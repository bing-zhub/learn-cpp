#include <bits/stdc++.h>
using namespace std;

struct cake{
    // 库存 单价 总售价
    double store, price, sell;
} cakes[1010];

bool cmp(const cake a, const cake b){
    return a.price > b.price;
}

int main(){
    int types;
    double demands;
    cin >> types >> demands;
    for(int i = 0; i < types; i++){
        scanf("%lf", &cakes[i].store);
    }

    for(int i = 0; i < types; i++){
        scanf("%lf", &cakes[i].sell);
        cakes[i].price = cakes[i].sell/cakes[i].store;
    }

    sort(cakes, cakes+types, cmp);

    double income = 0;
    for(int i = 0; i < types; i++){
        if(cakes[i].store <= demands){
            income += cakes[i].sell;
            demands -= cakes[i].store;
        }else{
            income += cakes[i].price * demands;
            break;
        }
    }

    cout << income;
    return 0;
}