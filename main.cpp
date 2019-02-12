//
// Created by 朱兵 on 2019/2/10.
//

#include <bits/stdc++.h>
using namespace std;


int main(){

    //vector 容器(单口: 从一端操作)
    // 动态数组(可变数组)

    // 动态增长: 开辟一个更大的 将旧有元素复制到新容器 释放旧空间

    // 初始化
    vector<int> v1;

    int arr[] = {10, 20, 30, 40};

    vector<int> v2(arr, (arr + sizeof(arr)/sizeof(int)) ); // vector(begin, end)

    vector<int> v3(v2.begin(), v2.end());

    vector<int> v4(v3);

    for(auto it = v4.begin(); it != v4.end(); it++){
        cout << *it << " ";
    }

    cout << endl;

    // 赋值

    //成员方法
    v1.assign(v2.begin(), v2.end());

    //重载=
    v3 = v1;

    v3.swap(v1); // 把v3与v1中的值进行交换(交换指针)



    return 0;
}