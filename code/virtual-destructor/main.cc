#include <iostream>

class Class1 {
    public:
        // This declaration causes memory leak
        //~Class1();
        // This declaration causes memory to be deallocated properly
        virtual ~Class1() = 0;
};

Class1::~Class1() = default;

class Class2 : public Class1 {
    public:
        Class2() {
            std::cout << "Allocating data" << std::endl;
            important = new int;
            *important = 42;
        }

        ~Class2() {
            std::cout << "Deallocating allocated data" << std::endl;
            delete important;
        }
    private:
        int* important;
};

int main() {
    Class1* c = new Class2();
    delete c;
}
