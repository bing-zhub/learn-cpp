#include <bits/stdc++.h>
using namespace std;
struct Poly{
    int exp;
    double cof;
} poly[1001];
double ans[2001];
int main(){
    int n,m,number=0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> poly[i].exp >> poly[i].cof;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int tExp;
        double tCof;
        cin >> tExp >> tCof;
        for(int j = 0; j < n; j++){
            ans[tExp+poly[j].exp] += (tCof * poly[j].cof);
        }
    }
    for(int i = 0; i <= 2000; i++) if(ans[i] != 0.0) number++;
    printf("%d",number);
    for(int i = 2000; i >= 0; i--){
        if(ans[i]!=0.0) printf(" %d %.1f",i,ans[i]);
    } 
    return 0;
}