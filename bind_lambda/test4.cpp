#include <iostream>
#include <functional>
#include <algorithm>
#include <memory>

void proc(int* x){
    
}

auto func(){
    int x;
    // 参数直接复制, 如果仅拷贝地址, 会出现问题
    return std::bind(proc, &x); // 指向局部
}

void proc_1(std::shared_ptr<int> ptr){

}

auto func_1(){
    std::shared_ptr<int> x(new int(5));
    return std::bind(proc_1, x);
}

void incre(int &x){
    ++x;
}

int main(){
    // 编译可通过, 可运行, 但一定会有问题
    func(); 

    // 可通过智能指针解决
    func_1();

    int x = 0;
    incre(x);
    std::cout << x << std::endl; // 1

    // 复制传递, 复制x得到x`, 将x`传递给incre 
    auto b = std::bind(incre, x);
    b();
    std::cout << x << std::endl; // 1

    // 传递引用
    auto b1 = std::bind(incre, std::ref(x));
    b1();
    std::cout << x << std::endl; // 2
}