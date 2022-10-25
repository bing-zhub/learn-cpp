#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

// 1. 将vector 填充为 1~100
// 2. 对每个数平方
// 3. 取出能被4整除的数
// 4. 输出前5个

int main(){
    // c++ 20之前
    std::vector<int> v(100), v1;
    // 1.
    std::iota(v.begin(), v.end(), 1);
    // 2.
    std::transform(v.begin(), v.end(), v.begin(), 
                   [](int val){ return val*val;});
    // 3.
    std::copy_if(v.begin(), v.end(), std::back_inserter(v1),
                   [](int val){ return val % 4 == 0;});
    // 4.
    for(int i = 0; i < 5; i++)
        std::cout << v1[i] << std::endl;

    // c++ 20之后
    using namespace std::ranges;
    for (int i : views::iota(1)
    | views::transform( [] (int i) { return i*i; } )
    | views::filter( [] (int i) { return i % 4 == 0; } )
    | views::take(5)) {
        std::cout << i << ' ';
    }
}