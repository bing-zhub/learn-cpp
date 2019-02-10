//
// Created by 朱兵 on 2019/2/9.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    //标准输出
//    cout << "HelloWorld" << endl;
//    cout.put('h').put('e').put('l') << endl;
//    cout.write("HelloWorld", strlen("HelloWorld"));

    int number = 10;

    // 格式化输出

    //成员方法
    cout.unsetf(ios::dec); // 卸载十进制
    cout.setf(ios::oct); // 装载八进制
    cout.setf(ios::showbase); // 显示引导符 '0'
    cout << number << endl;

    cout.unsetf(ios::oct); // 一定要卸载
    cout.setf(ios::hex); // 装载十六进制进制
    cout.setf(ios::showbase); // 显示引导符 '0'
    cout << number << endl;

    cout.width(10); // 宽度
    cout.fill('*'); // 填充
    cout.setf(ios::left); // 对齐方式
    cout<<number<<endl;

    //控制符
    cout << hex
         << setiosflags(ios::showbase)
         << setw(10)
         << setfill('~')
         << setiosflags(ios::left)
         << number
         << endl;



    return 0;
}