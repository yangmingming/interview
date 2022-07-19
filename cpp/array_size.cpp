#include <iostream>
#include <string>
#include <vector>

int main(){
    char rows[9][9];
    char colums[9][9];
    char sudoku[3][3][9];

    std::cout << "rows size = " << sizeof(rows) << std::endl;
    std::cout << "colums size = " << sizeof(colums) << std::endl;
    std::cout << "sudoku size = " << sizeof(sudoku) << std::endl;

    return 0;
}

