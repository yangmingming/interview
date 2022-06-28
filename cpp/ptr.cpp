#include <iostream>
// std::shared_ptr std::uniqe_ptr std::weak_ptr
#include <memory>

class B;
class A
{
    public:
        std::shared_ptr<B> pb_;
        ~A()
        {
            std::cout<<"A delete\n";
        }
};

class B
{
    public:
        // 使用std::shared_ptr, 因为存在循环引用，导致引用计数不能降为0,导致析构函数不能执行
        //std::shared_ptr<A> pa_;

        // 通过std::weak_ptr,不增加引用计数
        std::weak_ptr<A> pa_;
        ~B()
        {
            std::cout<<"B delete\n";
        }
};

void check_shared_ptr()
{
    std::shared_ptr<B> pb(new B());
    std::shared_ptr<A> pa(new A());

    std::cout<<pb.use_count()<<std::endl;
    std::cout<<pa.use_count()<<std::endl;

    // 循环引用
    pb->pa_ = pa;
    pa->pb_ = pb;

    std::cout<<pb.use_count()<<std::endl;
    std::cout<<pa.use_count()<<std::endl;
}

int main()
{
    check_shared_ptr();
    return 0;
}
