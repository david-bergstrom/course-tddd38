#include <iostream>

#include "Container.h"
#include "Tracer.h"

template<typename T>
void print(Container<T>& t) {
    std::cout << "Container at: " << &t
        << "\nSize:" << t.size()
        << "\nCapacity: " << t.capacity()
        << "\nEmpty: " << (t.empty() ? "yes" : "no") << std::endl;
}

Container<int> something() {
    Container<int> c(10);
    return c;
}

int main() {
    Container<Tracer<int>> c1(10);

    print(c1);

    std::cout << "\nTime to copy!" << std::endl;
    auto c2 { c1 }; 

    print(c2);

    std::cout << "\nTime to move!" << std::endl;
    auto c3 {something()};

    print(c3);

    std::cout << "Everything going out of scope!" << std::endl;
}
