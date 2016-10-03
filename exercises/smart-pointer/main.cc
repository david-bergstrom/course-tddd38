#include <iostream>
#include <assert.h>
#include "smart_pointer.h"

using namespace std;

void smart_pointer::debug() {
    cout << "Current address " << ptr_ << endl;
}

void test() {
    int * raw { new int { 3 } };
    smart_pointer smart { raw };

    assert(!!smart);
    assert(smart == smart);
    assert(!(smart != smart));

    smart_pointer smart_null;

    assert(!smart_null);
    assert(smart != smart_null);

    smart_pointer smart_copy { smart };
    assert(*smart == *smart_copy);
}

int main() {
    smart_pointer sp = smart_pointer();
    sp.debug();

    smart_pointer sp2 { new int { 3 } };
    sp2.debug();

    test();

    return 0;
}
