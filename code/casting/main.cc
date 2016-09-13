#include <iostream>
#include <vector>

using namespace std;

// static_cast
void sc() {
	int x = 5;

	// Casting to a float
	float f = static_cast<float>(x);

	// Casting to a list
	vector<int> v = static_cast<vector<int>>(x);

	cout << v.size() << endl;
}

// const_cast
void cc() {
	const int always_same_number = 5;
}

int main() {

}
