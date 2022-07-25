#include <iostream>
#include <string>
#include <vector>
#include <string.h>

//bool isValidShudu(int[][9] arr){
bool isValidShudu(int arr[][9]){
    int rows[9][9];
    int columns[9][9];
    // 3*3
    int sub[3][3][9];

    memset(rows, 0x00, sizeof(rows));
    memset(columns, 0x00, sizeof(columns));
    memset(sub, 0x00, sizeof(sub));

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int value = arr[i][j];
            if(value == '.'){
                continue;
            }

           std::cout << "[" << i << "," << j << "]" << "->" << arr[i][j] << std::endl;

            int v = value;
            rows[i][v]++;
            columns[j][v]++;
            sub[i/3][j/3][v]++;

            if(rows[i][v] > 1 || columns[j][v] > 1 || sub[i/3][j/3][v] > 1){
                std::cout << "rows " << i << "," << v << "," << rows[i][v] << std::endl;
                std::cout << "columns " << j << "," << v << "," << columns[j][v] << std::endl;
                std::cout << "sub" << i << "," << j  << "," << v << "," << sub[i][j][v] << std::endl;
                return false;
            }
        }
    }

    return true;
}


// 注意:构造数独的时候,需要保证数字1和'1'的区别
int main(){
    int arr[9][9] = {
        {1, '.',     3,   4, '.', '.',   2, '.', '.'},
        {'.',   2, '.', '.', '.', '.',   0, '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {4, '.',   '.', '.', '.', '.', '.', '.', '.'},
        {'.',   6, '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.',   7, '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.',   2, '.', '.', '.', '.', '.'},
        {2, '.',   '.', '.', '.', '.', '.', '.','.'},
        {'.','.',    1, '.', '.', '.', '.', '.','.'}
    };

    bool ret = isValidShudu(arr);

    std::cout << "ret = " << ret << std::endl;

    int arr2[9][9] = {
        {1, '.',     3,   4, '.', '.',   2, '.', '.'},
        {'.',   2, '.', '.', '.', '.',   0, '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {4, '.',   '.', '.', '.', '.', '.', '.', '.'},
        {'.',   6, '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.',   7, '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.',   2, '.', '.', '.', '.', '.'},
        {2, '.',   '.', '.', '.', '.', '.', '.','.'},
        {'.', 2,    1, '.', '.', '.', '.', '.','.'}
    };

    ret = isValidShudu(arr2);

    std::cout << "ret = " << ret << std::endl;

    return 0;
}
