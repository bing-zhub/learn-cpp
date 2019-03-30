#include <bits/stdc++.h>
using namespace std;

//bign = big number
struct bign{
    int d[1000];
    int len;
    bign(){ //构造器 初始化参数
        memset(d, 0, sizeof(d));
        len=0;
    }
};

bign toBign(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i = 0; i < a.len; i++){
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}


// a > b -> 1
// a < b -> -1
// a = b -> 0
int greaterThan(bign a, bign b){
    if(a.len > b.len)
        return 1; 
    else{
        for(int i = a.len-1; i >=0; i--){ // from higher base to lower base
            if(a.d[i] > b.d[i]){
                return 1;
            }else if(a.d[i] < b.d[i]){
                return -1;
            }
        }
        return 0;
    }
}

int main(){
    char str1[] = "123456";
    char str2[] = "234567";
    bign a = toBign(str1);
    bign b = toBign(str2);
    cout << greaterThan(b,a);
    return 0;
}