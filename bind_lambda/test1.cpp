#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

bool myPredict(int val){
    return val > 3;
}

int main(){
    std::vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> y;
    // 输入区间, [x.begin(), x.end()]
    // 输出到 std::back_inserter(y) push_back到y中
    // 函数定义复杂, 位置受限
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), myPredict);
    for(auto p : y){
        std::cout << p << " " ;
    }
    std::cout <<  std::endl;
}