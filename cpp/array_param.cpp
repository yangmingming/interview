
#include <iostream>
#include <string>
#include <vector>

// 传数组,第二维必须标明
void display1(int array[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << array[i][j] << "\t";
        }

        std::cout << std::endl;
    }
}

// 传数组指针，二维必须指定
// 注意数组
void display2(int (*array)[3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << array[i][j] << "\t";
        }

        std::cout << std::endl;
    }
}

// 传一维指针
void display3(int *array){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << *(array + i * 3 + j) << "\t";
        }

        std::cout << std::endl;
    }
}

// 数组指针 + 指针数组
void test_point(){
    // 指针数组,实际上是数组,里面存储了3个指针
    const char *arr[] = {"hello", "world", "shannxi"};
    
    // 数组指针,实际上是一个指针，指向一个数组
    int array[][2] = { 1, 2, 3, 4, 5, 6};
    int (*p)[2] = array;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            std::cout << "[" << i << "," << j << "]" << "->" << p[i][j] << std::endl;
        }
    }
    std::cout << std::endl;

}

// 扩展阅读:https://www.cnblogs.com/cygalaxy/p/6963789.html
int main(){
    // 多维数组‘array’的声明必须至少指定除第一维以外所有维的大小
    int array[][3] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    display1(array);
    display2(array);
    // 二维指针强转成一维指针
    display3((int *)array);

    // 验证指针数组和数组指针
    test_point();

    return 0;
}
