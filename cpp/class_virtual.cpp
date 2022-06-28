#include <iostream>

// 为什么基类虚构函数需要设置为虚函数
class Base {
public:
    Base(){
        std::cout << "base constructor" << std::endl;
        p = new char;
    }

    // 如果基类中的析构函数未指定为virtual,基类析构就不会调用子类的析构函数
    virtual ~Base(){
        std::cout << "base destructor" << std::endl;
        if(p != nullptr){
            delete(p);
            p = nullptr;
        }
    }

    virtual void Show(){
        std::cout << "show" << std::endl;
    }

    char *p = nullptr;
};

class Sub : public Base {
public:
    Sub(){
        std::cout << "sub constructor" << std::endl;
        q = new char;
    }

    ~Sub(){
        std::cout << "sub destructor" << std::endl;
        if(q != nullptr){
            delete(q);
            q = nullptr;
        }
    }

    char *q = nullptr;
};

int main(){
    Base *a = new Sub();

    std::cout << "-----------" << std::endl;

    delete(a);

    return 0;
}
