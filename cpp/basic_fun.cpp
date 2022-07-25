
#include <iostream>
#include <string>
#include <vector>

int main(){
    // std::tolower 大小写转换,仅英文字符才会转换
    std::string str = "12AbCd ,";
    for(auto &c : str){
        std::cout << "lower: " << c << " -> " << (char)std::tolower(c) << std::endl;
    }

    for(auto &c : str){
        std::cout << "upper: " << c << " -> " << (char)std::toupper(c) << std::endl;
    }


    // std::equal

    // std::sort 
    // https://en.cppreference.com/w/cpp/algorithm/sort

    // std::isdigit
    // std::isalpha

    return 0;
}
