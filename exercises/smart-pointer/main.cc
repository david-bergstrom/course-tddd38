#include <iostream>
#include "smart_pointer.h"

using namespace std;

void smart_pointer::debug() {
    cout << "Current address " << ptr_ << endl;
}

int main() {
    smart_pointer sp = smart_pointer();
    sp.debug();

    smart_pointer sp2 { new int { 3 } };
    sp2.debug();

    return 1;
}
