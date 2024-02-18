// Type your code here, or load an example.
#include <iostream>
#include <string>

class MyClass
{
public:
    MyClass(int i, std::string n) : id(i), name(n) {}
    int id;
    std::string name;
};

void swap(MyClass& a, MyClass& b)
{
    auto temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

void foo(int&) { std::cout << "foo&" << std::endl; }
void foo(int&&) { std::cout << "foo&&" << std::endl; }
void boo(int&& i) { foo(i); }

int main(void) {
    std::cout << "hello, world" << std::endl;

    std::printf("%d\n", 1100);
    std::printf("%d\n", 2200);

    auto name = "class1";
    auto cls = new MyClass(1, name);

    int&& i = 3;
    foo(i);
    foo(3);
    //boo(i); //コンパイルエラー：左辺値参照を受け取る引数がないため
    boo(std::move(i));

    return 0;
}

