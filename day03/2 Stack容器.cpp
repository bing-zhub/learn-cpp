//
// Created by 朱兵 on 2019/2/11.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    // Stack 容器

    stack<int> s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.size() << " " << endl;


    cout << s1.top() << " " << endl;
    s1.pop();
    // pop只弹出栈顶元素 不返回

    cout << s1.empty() << " "<<endl;

    return 0;
}