
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

void display4(std::vector<std::vector<int>> &array){
    // auto遍历
    for(auto &vec: array){
        for(auto &item: vec){
            std::cout << item << "\t";
        }

        std::cout << std::endl;
    }

    // i,j遍历
    for(auto i = 0; i < array.size(); i++){
        for(auto j = 0; j < array[i].size(); j++){
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// 扩展阅读:https://www.cnblogs.com/cygalaxy/p/6963789.html
// https://zhjwpku.com/2020/03/14/initialize-two-dimensional-vector.html [初始化二维 vector 的几种方法]
int main(){
    // C语言数组相关
    {
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
    }

    // c++ vector相关
    {
        std::vector<std::vector<int>> array = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };

        display4(array);

        std::cout << "二维vector初始化相同的一维数组" << std::endl;

        // 对于二维vector初始化特定数据
        std::vector<std::vector<int>> array2(3, std::vector<int>{1,2,3});
        display4(array2);

        std::cout << "二维vector初始化相同数字" << std::endl;
        // 注:该方法初始化的是一个3*1的二维数组
        std::vector<std::vector<int>> array3(3, std::vector<int>{2});
        display4(array3);
        // 注:该方法初始化的是一个3*3的二维数组
        std::vector<std::vector<int>> array4(3, std::vector<int>(3, 0));
        display4(array4);

        // 总结:二维数组M*N的初始化方法
        // std::vector<std::vector<int>> matrix(M, std::vector<int>(N, 0));

    }

    return 0;
}
