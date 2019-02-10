//
// Created by 朱兵 on 2019/2/10.
//

#include <bits/stdc++.h>
using namespace std;

class Person{
public:
    int age;
    int id;

public:
    Person(int age, int id){
        this->age = age;
        this->id = id;
    }
};

//void printI(int v){
//    cout << v << " ";
//}

void printP(Person p){
    cout << " Age: "<<p.age << " ID:" << p.id << endl;
}
int main(){

    // Standard Template Library 标准模板库
    // 广义上分为 容器 算法 迭代器

    // 序列式容器 位置由时机和地点决定
    // 关联式容器 不由 ~

//    vector<int> v;
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);
//
//    for_each(v.begin(), v.end(), printI);

    vector<Person> v;
    Person p1(10,20), p2(30, 40), p3(50, 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

//    for_each(v.begin(), v.end(), printP);
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++){
        cout << " Age: "<<(*it).age << " ID:" << (*it).id << endl;
    }

    return 0;
}