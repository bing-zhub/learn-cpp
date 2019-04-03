#include <bits/stdc++.h>
using namespace std;
int n; // 有效位

string deal(string s, int & e){
    int k = 0;

    // 数据规整化

    // 001234 -> 1234
    while(s.length() >0 && s[0] == '0'){
        s.erase(s.begin());
    }

    if(s[0] == '.'){
        // 处理小于1的数
        // .001234 -> 001234 
        s.erase(s.begin());
        while(s.length() > 0 && s[0] == '0'){
            s.erase(s.begin());
            e--;
        }
        // 001234 -> (s,e) (1234,-2)
    }else{
        //处理大于1的数
        while(k < s.length() && s[k]!='.'){
            // 得到整数部分的值和指数
            k++;
            e++;
        }
        // 1234 -> (1234, 4)
        if(k < s.length()){
            // 去除小数点
            s.erase(s.begin() + k);
        }
    }

    // 处理完了之后长度为0 这个数就为0
    if(s.length() == 0)
        e = 0;

    int num = 0;
    k = 0;
    string res;
    while(num < n){ // 精度未到n
        if(k < s.length()) res += s[k++];
        else res += '0';
        num ++;
    }
    return res;
}

int main(){
    string s1,s2,s3,s4;
    cin >> n >> s1 >> s2;
    int e1 = 0, e2 =0;
    s3 = deal(s1, e1);
    s4 = deal(s2, e2);
    if(s3==s4 && e1==e2){
        cout << "YES 0."<<s3<<"*10^"<<e1<<endl;
    }else{
        cout << "NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
    }
    return 0;
}