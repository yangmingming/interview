#include <iostream>
#include <stack>

int main(){
    std::stack<int> s;
    
    // 判空
    std::cout << "empty: " << s.empty() << std::endl;

    // 插入
    s.push(1);
    s.push(3);
    s.push(5);

    // 长度
    std::cout << "size: " << s.size() << std::endl;

    // 头元素
    std::cout << "top: " << s.top() << std::endl;

    // pop栈顶元素
    s.pop();
    std::cout << "top: " << s.top() << std::endl;

    return 0;
}
