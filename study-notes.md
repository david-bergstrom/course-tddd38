# Private members without empty constructors

In C++11 and later one should use the [member initializer list](http://en.cppreference.com/w/cpp/language/initializer_list). It allows for having the objekts as members and initializing them in a list before the contructor.

Example:

~~~
class Class1 {
	public:
		Class1(int x) { }
};

class Class2 {
	public:
		// Without the initializing list here, the example won't compile
		Class2() : c1 {3} { }
	private:
		Class1 c1;
};

int main() {

}
~~~
