#include<iostream>
#include<string>

using namespace std;

template <typename T>
T func(T z) {
    return z + z;
}

int main() {
    cout << func(10) << endl;
    cout << func(string("Test")) << endl;
}
