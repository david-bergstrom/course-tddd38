#include <iostream>
using namespace std;

void
fun(int a, int b, int c, int d) {
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}

void f2(int a) {
    cout << a << endl;
}

int main()
{
    int n{ 20 };
    for (int i{ 0 }; i<n; --n) // Replacing i to n
        cout << 'x' << endl;

    int d, e, f, o, u, p, q, r = 0;

    f2((5, 0, 30));
    return 0;
}
