#include <iostream>
#include <queue>

int main(){
    std::queue<int> q;
    
    // 判空
    std::cout << "empty: " << q.empty() << std::endl;

    // 插入
    q.push(1);
    q.push(3);
    q.push(5);

    // 长度
    std::cout << "size: " << q.size() << std::endl;

    // 头元素
    std::cout << "front: " << q.front() << std::endl;
    // 尾元素
    std::cout << "back: " << q.back() << std::endl;

    // pop头元素
    q.pop();
    std::cout << "front: " << q.front() << std::endl;

    return 0;
}
