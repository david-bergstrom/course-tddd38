#include "iscopyassignable.h"

#include <string>
#include <iostream>

class A {
    A& operator=(A&) = delete;
};

int main() {
    static_assert(my_is_copy_assignable<std::string>::type::value);
    static_assert(!my_is_copy_assignable<A>::type::value);
    return 0;
}
