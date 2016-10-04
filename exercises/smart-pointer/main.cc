#include <iostream>
#include <assert.h>
#include "smart_pointer.h"

using namespace std;

void test() {
    // Initialization: constructor taking a raw pointer to an object
    int * raw { new int { 3 } };
    smart_pointer smart { raw };

    assert(!!smart);
    assert(smart == smart);
    assert(!(smart != smart));

    // Initialization: constructor taking nothing, resulting in nullptr
    smart_pointer smart_null;

    assert(!smart_null);
    assert(smart_null == nullptr);
    assert(!(smart_null != nullptr));
    assert(smart != smart_null);

    // Copying: Copy constructor
    smart_pointer smart_copy { smart };
    assert(*smart == *smart_copy);

    // Copying: Copy assignment
    smart_pointer smart_another_copy;
    smart_another_copy = smart;

    assert(smart != smart_another_copy); // Different pointers
    assert(!!smart_another_copy); // Not null pointer
    assert(*smart == *smart_another_copy); // Same value

    // Destruction: It should not be allowed to delete a smart_pointer
    smart_pointer smart2 { new int { 3 } };
    // The following line does not compile
    //delete smart2;
}

int main() {
    test();

    return 0;
}
