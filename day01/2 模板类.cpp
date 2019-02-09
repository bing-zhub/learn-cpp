//
// Created by 朱兵 on 2019/2/9.
//

#include <bits/stdc++.h>
using namespace std;

template <class T>  // template <typename T> 也可以
class Person{

public:
    Person(){

    }

    Person(T id, T age){
        this->mAge = age;
        this->mId = id;
    }

    void Show(){
        cout << "Id: "<< mId <<" Age: "<< mAge <<endl;
    }

public:
    T mId;
    T mAge;

};

// 模板类 派生普通类
class SubPerson : public Person<int >{

};

int main(){

    //模板类必须显式指明类型
    Person<int> p1(10,20);

    p1.Show();

    return 0;
}