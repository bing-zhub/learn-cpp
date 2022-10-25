#include <iostream>

int main(){
    // [捕获](参数){函数体};
    auto x1 = [](int val) { return val > 3; };
    std::cout << x1(5) << std::endl;
    // 类型可自动推导 
    auto x2 = [](int val) { 
        if(val > 3)
            return "Hello";
        else
            return "World"; 
    };
    std::cout << x2(4) << " " << x2(1) << std::endl;
    // 显式指定返回值类型
    auto x3 = [](int val) -> float{ 
        if(val > 3)
            return 1.0;
        else
            return 1.2f; 
    };
    std::cout << x3(4) << " " << x3(1) << std::endl;
}