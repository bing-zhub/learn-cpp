//
// Created by 朱兵 on 2019/2/9.
//

#include <bits/stdc++.h>
using namespace std;
// 普通函数可以进行类型自动转换
// 模板函数必须类型严格匹配
// 优先使用普通函数 加<> 可以使用模板函数
template <class T>  // template <typename T> 也可以
void mSwap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    cout << "hello";
    int a = 3, b = 4;

    // 1.自动类型推导
    mSwap(a,b);

    // 2.显式指定类型
    mSwap<int>(a, b);

    return 0;
}