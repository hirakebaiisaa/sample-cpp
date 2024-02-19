// Type your code here, or load an example.
#include <iostream>
#include <string>

void foo(int&) { std::cout << "foo&" << std::endl; }
void foo(int&&) { std::cout << "foo&&" << std::endl; }
void boo(int&& i) { foo(i); }

void testMoveSemantics()
{
    int&& i = 3;
    foo(i);
    foo(3);
    //boo(i); //コンパイルエラー：左辺値参照を受け取る引数がないため
    boo(std::move(i));
}

class ParentObj
{
    private:
    //ParentObj(int i, std::string n) = delete;
        std::unique_ptr<ParentObj> ptr = nullptr;

    public:

        void setImmobilized(std::unique_ptr<ParentObj>&& ptr)
        {
            this->ptr = std::move(ptr);
        }

        ~ParentObj()
         {
            std::cout << "ParentObj destructor" << std::endl;
        }
};

std::unique_ptr<ParentObj> fooP()
{
    return std::make_unique<ParentObj>();
}

void testAllocation()
{
    //auto obj = std::make_unique<ParentObj>(1, "name") >();
    //delete obj;

    auto fp = fooP();
    {
        ParentObj p;
        p.setImmobilized(std::move(fp));
    }
}


int main(void) {
    std::cout << "hello, world" << std::endl;
    auto name = "class1";

    //testMoveSemantics();
    testAllocation();

    return 0;
}

