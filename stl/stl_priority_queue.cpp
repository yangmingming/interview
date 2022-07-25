#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Stu{
    int id;
    std::string name;

    // 注意返回值也是const类型
    bool operator < (const Stu &s) const{
        return id < s.id;
    }
};

void manual_cmp(){
    std::priority_queue<Stu> q;
    q.push(Stu{1, "jack"});
    q.push(Stu{3, "look"});
    q.push(Stu{2, "seem"});

    /*
    // 注:如果使用引用的话，一旦pop,内存访问可能出现异常
    for(int i = 0; i < 3; i++){
        const Stu &item = q.top();q.pop();
        std::cout << (void *)&item << std::endl;

        std::cout << "val = " << item.id << std::endl;
    }
    */

    while(!q.empty()){
        // 注意返回值也是const类型
        const Stu &item = q.top();
        std::cout << item.id <<","<< item.name << std::endl;
        q.pop();
    }
}

int main() {
    // 初始化，忽略比较函数时,默认是大顶推
    //std::priority_queue<int> q;
    // 等价于
    //std::priority_queue<int, std::vector<int>, std::less<int>> q;

    // 小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    
    std::vector<int> vec{1,3,5,2,4,6};
    for(auto &item: vec){
        // 插入元素
        q.push(item);
    }

    std::cout << "size = " << q.size() << std::endl;
    std::cout << "empty = " << q.empty() << std::endl;
    std::cout << "top = " << q.top() << std::endl;

    while(!q.empty()){
        // 获取堆顶元素
        std::cout << q.top() << std::endl;

        // 弹出堆顶元素
        q.pop();
    }

    // 自定义比较函数,适用于复杂数据结构,需要实现operator < 函数
    manual_cmp();

    return 0;
}
