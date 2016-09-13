#include<iostream>
#include<string>

using namespace std;

int main()
{
    // Old style lambda
    auto old = [](int input) { return input + input; };

    // New style lambda
    auto fun = [](auto input) { return input + input; };

    cout << "Old style: " << old(10) << endl;
    cout << "New style: " << fun(10) << endl;

    cout << "Another example: " << fun(string("Test")) << endl;
}
