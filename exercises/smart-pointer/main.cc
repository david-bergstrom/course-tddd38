#include <assert.h>
#include <utility>
#include "smart_pointer.h"

using namespace std;

smart_pointer calculate() {
    int * raw { new int { 8 * 8 } };
    return smart_pointer(raw);
}

void test() {
    // Initialization: constructor taking a raw pointer to an object
    int * raw { new int { 3 } };
    smart_pointer smart { raw };

    assert(!!smart);
    //assert(smart);
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

    // Trying the move constructor
    smart_pointer smart3 { calculate() };

    // Trying out the move assignment using swap
    smart_pointer smart4 { new int { 3 } };
    smart_pointer smart5 { new int { 4 } };
    std::swap(smart4, smart5);
    assert(*smart4 == 4);
    assert(*smart5 == 3);
}

void pointer_variants() {
    // A pointer to a constant integer
    //const int* ptr1 { new int { 3 } };
    // A constant pointer to an int
    int* const ptr2 { new int { 4 } };
    // A constant pointer to a constant integer
    //const int* const ptr3 { new int { 5 } };

    // Which one can be used with smart_pointer?
    //smart_pointer sp1 { ptr1 };
    smart_pointer sp2 { ptr2 };
    //smart_pointer sp3 { ptr3 };
}

void const_tests() {
    const smart_pointer smart;
    const smart_pointer smart2 { new int { 3 } };
    const smart_pointer smart3 { smart2 };

    assert(smart != smart2);
    assert(*smart2 == *smart3);
}

int main() {
    test();
    pointer_variants();
    const_tests();

    return 0;
}
