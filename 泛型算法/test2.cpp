#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <ratio>
#include <vector>
#include <execution>

int main(){
    std::random_device rd;

    std::vector<double> vals(1000000);
    for(auto& d : vals){
        d = static_cast<double>(rd());
    }

    for(int i = 0; i < 5; i++){
        using namespace std::chrono;
        std::vector<double> sorted(vals);
        const auto startTime = high_resolution_clock::now();
        std::sort(sorted.begin(), sorted.end());
        const auto endTime = high_resolution_clock::now();
        std::cout << "Latency: "
                  << duration_cast<duration<double, std::milli>>(endTime - startTime).count()
                  << std::endl;
    }
    
}