
#include <iostream>
#include <string>
#include <vector>

std::pair<int, int>add(std::pair<int, int> &p){
    return {p.first + 1, p.second + 1};
}

// https://en.cppreference.com/w/cpp/utility/pair
int main(){
    // pair 初始化
    std::pair<int, int> p1{1, 2};
    std::pair<int, int> p2(3, 4);
    std::pair<int, int> p3 = std::make_pair<int, int>(5, 6);
    std::pair<int, int> p4 = std::make_pair(7, 8);

    // pair 访问
    std::cout << "p1: " << p1.first << ", " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << ", " << p2.second << std::endl;
    std::cout << "p3: " << p3.first << ", " << p3.second << std::endl;
    std::cout << "p4: " << p4.first << ", " << p4.second << std::endl;

    // pair 传参 + pair 返回
    // 结构化绑定
    auto [v1, v2] = add(p1);
    std::cout << "return : " << v1 << ", " << v2 << std::endl;
    auto p5 = add(p4);
    std::cout << "p5: " << p5.first << ", " << p5.second << std::endl;

    return 0;
}
