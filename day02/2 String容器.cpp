//
// Created by 朱兵 on 2019/2/10.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    // String 容器


    // String 初始化
    string s1;
    string s2(10, 'a');
    string s3("aasda");
    string s4(s3);
//
//    cout << s1 << endl;
//    cout << s2 << endl;
//    cout << s3 << endl;
//    cout << s4 << endl;

    // 赋值
//    s1 = "Hello";
//    s2.assign("Hello");
//    cout << s1 << endl;
//    cout << s2 << endl;

    // 取值

    // [] 越界 程序死掉
//    for (int i = 0; i < s1.length(); ++i) {
//        cout << s1[i];
//    }
//
//    cout << endl;

    // at 越界 异常可以被捕获
//    for (int j = 0; j < s1.length(); ++j) {
//        cout << s1.at(j);
//    }

    // 拼接
//    s1 += ' ';
//    s1 += "World";
//    s1.append("!");
//    s1.append("123456", 3);
//    cout << s1 << endl;

    // 查找和替换
//    cout << s1.find("l") << endl; // 前往后
//    cout << s1.rfind("l") << endl; // 后往前
//    cout << s1.find("l",3) << endl ; // 前往后 第三个开始找
//    s1.replace(0,2,"HE");
//    cout << s1 << endl;


    // 比较

//    s1 = "abc";
//    s2 = "abc";
//    cout << s1.compare(s2); // 相等返回0


    //子串
//    s1 = "abc";
//    cout << s1.substr(1) << endl; // 起始到结束的子串
//    cout << s1.substr(1,2) << endl;

//    s1 = "abc";
//    s1.insert(2, "d");
//    cout << s1 << endl;
//    s1.erase(2,1);
//    cout << s1 << endl;
//    s1.erase(1); // 删除到结尾
//    cout << s1 << endl;

    return 0;
}