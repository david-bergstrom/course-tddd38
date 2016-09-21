# Members objects without empty constructors

In C++11 and later one should use the [member initializer list](http://en.cppreference.com/w/cpp/language/initializer_list). It allows for having the objects as members and initializing them in a list before the contructor.

Example:

```c++
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
```

# Casting

TODO: Complete this

## `static_cast`

The method does not

## `const_cast`

# io::eof is wrong when used in a loop condition

The method io::eof returns true when a read has failed and does not guarrantee
the success of the next read.

[Example](http://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-considered-wrong)

# Declaration vs definition

A declaration introduces an identifier and describes its type/object/function.
Example:

```c++
extern int x;
extern int y;
void f();
class foo();
```

A definition actually instantiates the data or implements the function or class.

```c++
int x;
int y;
void f() { cout << "hello world" << endl; }
class foo() {};
```

An identifier can only be defined once but can be declared as many times as
needed.

# Bjarne Stroustrup solution to dangling pointers

Use only pointers for non-owner instances. Use `owner<T*>` to represent owners.
This allows the usage of analyzis programs which checks only owners delete
data.

https://www.youtube.com/watch?v=1OEu9C51K2A
0:58 typ

# Expression categories

* _lvalue_ - "something we can assign to", a function or an object
	* _glvalue_ - A general lvalue, either a _lvalue_ or a _xvalue_
* _xvalue_ - an eXpiring value, it can be "pilfered" meaning its resources 
  could be moved
* _rvalue_ - "something which can be copied",
	* _prvalue_ - A pure _rvalue_ which is a _rvalue_ which is not a _xvalue_

The name rule, if something has a name it's an _lvalue_, if not then it's a 
_rvalue_.

# The keyword "Mutable"

A `const` method cannot change any of the member variables of the class
instance. However if a member variable is marked with the keyword mutable it
can be changed. This is used in special cases.

In C++11 it can also be used to make a lambda function able to change variables
in its captured scope.

Link: http://stackoverflow.com/a/105061
