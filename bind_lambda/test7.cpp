#include <iostream>
#include <string>

struct Str
{
    auto func(){
        int val = 3;
        // x 既是通过this进行捕获 
        auto lam = [val, this](){
            return val > x;
        };
        return lam;
    }
    int x;
};

int main(){
    // 初始化捕获
    Str s;
    s.x = 1;
    auto ret = s.func();
    std::cout << ret() << std::endl; // 3>1, 1

    int x = 3;
    auto lam = [y = x](int val) {
        return val > y;
    };
    std::cout << lam(4) << std::endl; // 4>3, 1
    // 使用场景
    std::string str = "hello";
    auto lam2 = [s = std::move(str)](){
        std::cout << s << std::endl;
    };
    lam2(); // "hello"
    std::cout << str << std::endl; // ""

    int y = 1;
    // 初始化执行一次, 如果捕获[x,y], 每次调用lam3都会执行x+y => 提升性能
    auto lam3 = [z = x+y](int val){
        return val > z;
    };
    std::cout << lam3(4) << std::endl; // 1
} 