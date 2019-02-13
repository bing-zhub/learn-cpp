//
// Created by 朱兵 on 2019/2/11.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    // Deque 容器(双口容器)

    // 常数时间对头部进行插入删除

    deque<int> q1;

    q1.push_front(20);
    q1.push_front(30);
    q1.push_back(10);

    for(auto i: q1){
        cout << i << " ";
    }
    cout << endl;

    q1.pop_front();

    for(auto i: q1){
        cout << i << " ";
    }
    cout << endl;

    q1.pop_back();

    for(auto i: q1){
        cout << i << " ";
    }
    cout << endl;

    q1.assign(10, 0);

    for(auto i: q1){
        cout << i << " ";
    }
    cout << endl;

    q1.size();
    q1.empty();
    q1.resize(20, 10);

    q1.insert(q1.begin() + 2, 10);

    q1.clear();
    q1.erase(q1.begin(), q1.end());


    return 0;
}