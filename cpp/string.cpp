
#include <iostream>
#include <string>
#include <vector>

#include <bitset> //输出二进制的头文件

// https://blog.csdn.net/done1182818968/article/details/104713932 [C++的cout输出二进制，八进制]
void format(){
    int a = 1024;

    std::cout << "八进制:" << std::oct << a << std::endl;
    std::cout << "十进制:" << std::dec << a << std::endl;
    std::cout << "十六进制:" << std::hex << a << std::endl;
    std::cout << "二进制:" << std::bitset<sizeof(a) * 8>(a) << std::endl;
}

int main(){
    format();

    std::string str = "天明";
    std::cout << str.size() << std::endl;

    for(auto c : str){
        std::cout << c << "\t" << std::hex << std::bitset<sizeof(c) * 8>(c) << std::endl;
    }

    return 0;
}
