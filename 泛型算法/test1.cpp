#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iostream>
#include <numeric>

int main(){
    int x[100];
    std::sort(std::begin(x), std::end(x));
    
    // 从字符串中解析出int
    std::istringstream str("1 2 3 4 5");
    std::istream_iterator<int> y(str);
    std::istream_iterator<int> e{};
    // for(; y != e; y++){
    //     std::cout << *y << std::endl;
    // } 
    // 访问过一次后就移除
    int res = std::accumulate(y, e, 0);
    std::cout << res << std::endl;

    std::ostream_iterator<int> i1 {std::cout, ", "};
    std::fill_n(i1, 5, -1);
    *i1 = '\n';
    i1 ++;
    std::istringstream z0("1 2 3 4 5");
    std::istream_iterator<int> z(z0);
    std::copy(z, e, i1);
    std::cout << "\n";

    std::vector x2{1,2,3,4,5};
    std::copy(x2.rbegin(), x2.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::string str1 = "hello";
    std::string str2 = str1;
    std::cout << str1 << " " << str2 << std::endl;
    std::string str3 = std::move(str1);
    std::cout << str1 << " " << str3 << std::endl; // str1 为空
}
