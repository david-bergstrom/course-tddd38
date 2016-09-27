#include <iostream>
#include <vector>

using namespace std;

// static_cast, used between related types
void sc() {
	int x = 5;

	// Casting to a float
	float f = static_cast<float>(x);

	// Casting to a list
	vector<int> v = static_cast<vector<int>>(x);

	cout << "Vector size: " << v.size() << endl;
}

// const_cast, removes constant
void cc() {
	int always_same_number = 5;
	
	int const & number = always_same_number;

	int & another_reference = const_cast<int &>(number);

	cout << "Before change: " << number << endl;

	// Changing the number using the non-const reference
	another_reference = 10;

	cout << "After change: " << number << endl;
}

// dynamic_cast, withing a polymorphic class hierarchy
void dc() {
	class A {
		public:
			// Having a virtual method makes the class polymorphic. Also,
			// having a virtual destructor helps, as this forces C++ to use the
			// deconstructor in the child-classes instead, allowing them to
			// clean up any allocated memory.
			virtual ~A() {};
	};

	class B : public A {
		public:
			void print() {
				cout << "What's up?? I'm B!" << endl;
			}
	};

	class C : public A {
		public:
			void print() {
				cout << "What's up?? I'm C!" << endl;
			}
	};

	vector<A*> v;
	v.push_back(new B);
	v.push_back(new C);

	for (A* object : v) {
		if (B* b = dynamic_cast<B*>(object)) {
			b->print();
		} else if(C* c = dynamic_cast<C*>(object)) {
			c->print();
		}
		delete object;
	}
}

int main() {
	sc();
	cc();
	dc();
	// There is also reinterpret_cast which simply reinterprets the memory as
	// something else, which can be quite dangerous.
	
	// Finnaly there are two kinds of casting: C-style cast (type) value and
	// function-style cast type(value) both which should be avoided.
}
