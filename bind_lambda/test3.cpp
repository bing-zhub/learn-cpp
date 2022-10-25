#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

bool myPredict(int val1, int val2){
    return val1 > val2;
}

bool myAnd(bool val1, bool val2){
    return val1 && val2;
}

int main(){

    using namespace std::placeholders;

    std::vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> y;
    // 输入区间, [x.begin(), x.end()]
    // 输出到 std::back_inserter(y) push_back到y中
    // _1 代表调用函数时, 传入的第一个参数
    // myPredict 第一个参数被占位符替代 后续传入, 第二个参数固定为3
    // std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind(myPredict, _1, 3));
    // 或者 第一个参数固定为3, 第二个参数由占位符代替, 后续传入
    // 按位置区分 
    
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind(myPredict, 3,  _1));
    for(auto p : y){
        std::cout << p << " " ;
    }

   
    std::cout <<  std::endl;

    auto r0 = std::bind(myPredict, _1, 3);
    std::cout << r0(4) << std::endl; // 4 > 3, true
    auto r1 = std::bind(myPredict, _2, 3); // 取调用函数的第二个参数作为原函数的第一个参数
    std::cout << r1("hello", 4) << std::endl; // 4 > 3, true
    auto r2 = std::bind(myPredict, 3, _1);
    std::cout << r2(1) << std::endl; // 3 > 1, true

    // bind也可以嵌套组合
    auto r3 = std::bind(myAnd, r0, r2);
    std::cout << r3(1) << std::endl; // 1>3 && 3>1, false

    // 也可以传入相同参数 
    auto r4 = std::bind(myPredict, _1, _1);
    std::cout << r4(11111) << std::endl; // 11111 > 11111, false

    auto r5 = std::bind_front(myPredict, 1);
}