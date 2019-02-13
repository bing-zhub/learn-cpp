//
// Created by 朱兵 on 2019/2/11.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    // Queue 容器

    queue<int> q1;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "size: " << q1.size() << endl;

    while (!q1.empty()){
        cout << q1.front() << " "; //访问队首元素
        q1.pop();
    }
    cout << endl;

    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << q1.back() << " "; // 访问队尾元素


    return 0;
}