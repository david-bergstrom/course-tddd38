#include <iostream>

using namespace std;

struct Point2D {
    double X;
    double Y;
    bool alive;
};

void array_function(int values []) {
    cout << "array function: ";
    for (int i = 0; i < 5; i++) {
        cout << values[i];
    }
    cout << endl;
}

/*
TODO: Does not work
int[5] array_return() {
    return {1, 2, 3, 4 ,5};
}
*/

void arrays() {
    int a1 [] = { 1, 2, 3, 4, 5 };

    for (auto i : a1) {
        cout << i << " ";
    }
    cout << endl;

    int * a2 = new int[5] { 1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        cout << a2[i] << " ";
    }
    cout << endl;

    // TODO: Does not work
    //array_function({5, 4, 3, 2, 1});
    
    // A.7: Cannot assign on the right-hand side
    //a1 = {5, 4, 3, 2, 1};
    
    // A.8: cannot use list initialization
}

int main() {
    arrays();
}
