#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <map>

int main(){
    std::vector<int> x{1,2,3,4,5,6};
    // auto it = std::ranges::find(x, 3);
    auto it1 = std::find(x.begin(), x.end(), 3);
    std::cout << *it1 << std::endl;

    auto it2 = std::ranges::find(x, 3);
    std::cout << *it2 << std::endl;

    std::map<int, int> m{{1,2}, {2,3}};
    auto it = std::ranges::find(m, 3, &std::pair<const int, int>::second);
    std::cout << it->first << " " << it->second << std::endl;
}