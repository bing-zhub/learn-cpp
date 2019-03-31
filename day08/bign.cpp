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

bign add(bign a, bign b){
    bign c;
    int carry = 0;
    for(int i = 0; i < max(a.len, b.len); i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }

    if(carry!=0)
        c.d[c.len++] = carry;
    return c;
}

bign sub(bign a, bign b){
    bign c;
    for(int i = 0; i < max(a.len, b.len); i++){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len - 1>=1 && c.d[c.len -1] ==0) // 去除高位的0, 并且保证至少有一个
        c.len --;
    
    return c;
}

int main(){
    char str1[] = "123456";
    char str2[] = "234567";
    bign a = toBign(str1);
    bign b = toBign(str2);
    cout << greaterThan(b,a) << endl;

    bign c = add(a,b);
    for(int i = c.len-1; i >=0; i--){
        cout << c.d[i];
    }
    cout << endl;

    bign d = sub(b,a);
    for(int i = d.len-1; i >=0; i--){
        cout << d.d[i];
    }
    return 0;
}