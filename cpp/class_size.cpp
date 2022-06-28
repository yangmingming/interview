#include <iostream>

// 空类的大小
// 所谓类的实例化就是在内存中分配一块地址，每个实例在内存中都有独一无二的地址。同样空类也会被实例化，所以编译器会给空类隐含的添加一个字节，这样空类实例化之后就有了独一无二的地址了。所以空类的sizeof为1
class Stu1{ };

// 非空类的存储空间以包含变量的存储大小为准
class Stu2{ int a; };

// 非空类,包含函数不占用存储空间
// 类的大小与它的构造函数、析构函数和其他成员函数无关，只已它的数据成员有关。
class Stu3{ 
public:
    ~Stu3(){};
    void fun(){};
    int a; 
};

// 非空类,包含虚函数，会因为多一个虚函数指针(vptr)指向虚函数表
// 而且会自动对齐,所以存储是8(vptr指针) + 4(int) + 4(补齐)
class Stu4{ 
public:
    virtual ~Stu4(){};
    int a; 
};

// 同上,无补齐,还是16字节
class Stu5{ 
public:
    virtual ~Stu5(){};
    int a; 
    int b; 
};

// 有虚函数的继承，子类的存储是父类的存储+子类的存储
// 不过因为父类的变量+子类的变量不需要补齐,所以存储是16
// 注:只有一个虚函数指针(vptr)的大小
class Stu6 :public Stu4 { 
public:
    virtual ~Stu6(){};
    int c; 
};

// 同上
// 添加变量之后，内存补齐会多8字节 24字节
class Stu7 :public Stu4 { 
public:
    virtual ~Stu7(){};
    int c; 
    char d;
};

// 静态变量，不占用实例的存储空间
class Stu8{ 
public:
    int a; 
    static int b;
};

/*
 * 总结
 * 空类实例化需要一个独立的地址,因此编译器会为空类添加一个字节,因此空类的大小是1
 * 类中的成员函数不占用空间，成员变量才占用空间
 * 静态(static)成员变量不占用空间
 * 类中的变量计算存储大小的时候，需要考虑内存对齐
 * 如果包含虚函数,会因为增加一个虚函数指针(vptr)多一个指针的存储空间
 * 子类继承父类的时候，存储空间需要考虑基类的成员+子类自己的成员
 * 如果基类包含虚函数,子类继承的时候，也会包含虚函数指针,而且只有一个vptr
 **/

int main(){
    std::cout << sizeof(Stu1) << std::endl;
    std::cout << sizeof(Stu2) << std::endl;
    std::cout << sizeof(Stu3) << std::endl;
    std::cout << sizeof(Stu4) << std::endl;
    std::cout << sizeof(Stu5) << std::endl;
    std::cout << sizeof(Stu6) << std::endl;
    std::cout << sizeof(Stu7) << std::endl;
    std::cout << sizeof(Stu8) << std::endl;

    return 0;
}
