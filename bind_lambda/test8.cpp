#include <iostream>
#include <map>
#include <functional>

auto fun(int val){
   return val + 1;
}

auto fun(double val){
    return val + 1;
}

int fact(int n ){
    return n > 1 ? n * fact(n-1) : 1;
}

int main(){
    int y = 1;
    // 如果不加mutable, 实现时会自带const, 函数体内变量不可修改.
    auto l1 = [y](int val) mutable {
        ++y;
        return val > y;
    };

    // 捕获时计算 
    int x = 1;
    auto l2 = [z = x+y](){
        return z;
    };
    l2();

    // 即调用函数表达式, 匿名函数直接调用
    const auto val = [z = x * (x+y)](){
        return z;
    }();
    std::cout << val << std::endl;

    std::map<int, int> m{{2,3}};
    auto l3 = [](const auto& p){
        return p.first + p.second;
    };
    std::cout << l3(*m.begin()) << std::endl;

    // Lifting
    // auto b = std::bind(fun, 3); // fun定义混淆 编译报错
    auto b = [](auto x) {
        return fun(x);
    };
    std::cout << b(1) << std::endl; 
    std::cout << b(1.2) << std::endl;

    // 递归调用
    std::cout << fact(5) << std::endl;
    auto l_fact = [](int n){
        auto f_impl = [](int n, const auto& impl) -> int {
            return n > 1 ? n * impl(n-1, impl) : 1; 
        };
        return f_impl(n, f_impl);
    };
    std::cout << l_fact(5) << std::endl;
}   