#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
double poly[N];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a; double b;
        scanf("%d%lf", &a, &b);
        poly[a] = b;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a; double b;
        scanf("%d%lf", &a, &b);
        poly[a] += b;
    }
    int count = 0;
    for(int i = N; i >= 0; i--){
        if(poly[i]){
            count ++;
        }
    }

    printf("%d", count);
    for(int i = N; i >= 0; i--){
        if(poly[i]){
            printf(" %d %.1f", i, poly[i]);
        }
    }
    return 0;
}