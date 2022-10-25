#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

// greater
// constexpr bool operator()(const T &lhs, const T &rhs) const 
// {
//     return lhs > rhs; // assumes that the implementation uses a flat address space
// }


int main(){
    std::vector<int> x{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> y;
    // 输入区间, [x.begin(), x.end()]
    // 输出到 std::back_inserter(y) push_back到y中
    // greater接收两个参数, bind2nd把第二个参数固定为3, 仅接收第一个参数 
    // std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind2nd(std::greater<int>(), 3));
    // 或者
    std::copy_if(x.begin(), x.end(), std::back_inserter(y), std::bind1st(std::less<int>(), 3));
    // 但bind1st / bind2nd 对调用对象有限制, 只有部分可以使用, 由此引入bind
    for(auto p : y){
        std::cout << p << " " ;
    }
    std::cout <<  std::endl; 
}