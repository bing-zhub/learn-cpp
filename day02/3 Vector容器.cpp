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


    // 大小操作

    v4.size(); // v4的大小
    v4.empty(); // v4空返回true 否则false
    v4.resize(10, 1); // 将v4大小变为10 新位置由1填充 若未指定 则以0填充 如果小于原长 则删除
    v4.capacity(); // v4的容量 size && capacity
    v4.at(1); // 同样有[] 与string类似 at抛异常 []出错
    v4.front(); // 返回第一个元素 v4.begin() 返回一个迭代器
    v4.back(); // 返回最后一个元素 同上


    // 插入删除
    v4.push_back(10); // 末尾插入一个
    v4.pop_back(); // 删除末尾并返回
    v4.insert(v4.begin(), 20); // 头插法
    v4.insert(v4.begin() + 2, 10); // 在第二个位置插入 vector支持随机访问
    //支持下标访问 都支持随机访问
    v4.erase(v4.begin()); //删除第一个元素
    v4.erase(v4.begin()+1, v4.end()); // 删除区间
    v4.clear(); //删除所有





    return 0;
}