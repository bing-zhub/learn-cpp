#include <iostream>

int main(){
    int y = 10;

    // 捕获y(复制, 构造时传入)
    auto y1 = [y](int val) {
        return val > y; 
    };
    std::cout << y1(1) << std::endl; // 0

    // 值捕获, 复制进入
    auto y2 = [y](int val) mutable {
        y++;
        return val > y;
    };
    std::cout << y2(11) << std::endl; // 0
    std::cout << y << std::endl; // 10, 传递不到外部 

    // 引用捕获
    auto y3 = [&y](int val) mutable {
        y++;
        return val > y;
    };
    std::cout << y3(11) << std::endl; // 0
    std::cout << y << std::endl; // 11 \

    // 混合捕获
    int z = 1;
    auto y4 = [z, &y](int val) mutable {
        y++;
        return z > y;
    };
    std::cout << y3(11)  << std::endl; // 0
    std::cout << y << std::endl; // 11 

    // 局部变量自动将值捕获
    auto y5 = [=](int val){ return val > y; };
    // 局部变量自动将引用捕获
    auto y6 = [&](int val){ return val > y; };
    // 局部变量自动将引用捕获, 但z除外; [=, &z]则相反
    auto y7 = [&, z](int val){ return val > y; };
}