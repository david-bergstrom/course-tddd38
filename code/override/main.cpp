#include <iostream>

using std::cout;
using std::endl;

class Base {
    public:
    virtual void play() {
        cout << "Base class" << endl; 
    }
};

class Derived : public Base {
    public:
    void play() override {
        cout << "Derived class" << endl;
    }
};

int main() {

    Derived b;
    Base d = b;
    b.play();
    
    return 0;
}
