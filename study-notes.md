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

# `io::eof` is wrong when used in a loop condition

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
This allows the usage of analysis programs which checks only owners delete
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

# The keyword "mutable"

A `const` method cannot change any of the member variables of the class
instance. However if a member variable is marked with the keyword mutable it
can be changed. This is used in special cases.

In C++11 it can also be used to make a lambda function able to change variables
in its captured scope.

Link: http://stackoverflow.com/a/105061

# Running static checks on source code using clang-tidy

In Arch Linux the static analysis tool clang-tidy is available in the package
`clang-tools-extra`.

It can be invoked using the following in the terminal:
`clang-tidy main.cpp -- -std=c++1y`.

# Auto type deduction in ranged based for loops

Summary from taken from [Petr Zemeks blog entry with the same 
name](https://blog.petrzemek.net/2016/08/17/auto-type-deduction-in-range-based-for-loops/).

* Use `auto` when you want to work with a copy of elements in the range.
* Use `auto&` when you want to modify elements in the range in non-generic 
  code.
* Use `auto&&` when you want to modify elements in the range in generic code.
* Use `const auto&` when you want read-only access to elements in the range 
  (even in generic code).

# Polymorphism

## Virtual methods

Every method can be overridden in subclasses, but virtual methods are 
different. If a regular method method gets overridden it only applies for that 
class and pointers to that class. But if a virtual method is overridden it will 
also work when the pointer is downcasted to a superclass.

## Pure virtual method

A virtual method with no definition. Syntactically their definition is replaced 
with `=0`.

## Abstract base classes

An abstract base class is a class which has at least one pure virtual method 
and thus cannot be instantiated. These classes are only to be used as base 
classes.

## NVI pattern

For more advanced interfaces where there might exist a common behavior the 
non-virtual interface design pattern might be useful.

The interface consists of one public method which is not supposed to be 
overridden while having a private virtual method which is supposed for the 
purpose of overriding in the subclasses.

The public method contains the common behaviour while the private method 
contains the behavior specific to that particular superclass.

# Explicit

If a compiler cannot find an comparison between two objects (maybe only works 
for equality) it will make an implicit conversion of any two objects.

It may use any method which takes no argument or any constructor which only 
takes one argument.

# Smart pointers

`auto_ptr` contains the raw pointer to the object and the ownership is given to 
the last instance where the pointer was received. This might be problematic as 
the last instance might not be were the data should be deleted. **Deprecated**

`unique_ptr` (`scoped_ptr` in boost) does not allow the transfer of ownership. 
It has support for a custom delete function.

`shared_ptr` contains a pointer to a data itself and a pointer to the reference 
container. In the container we have a pointer, deleter function and a strong 
reference counter and weak reference counter.

`make_shared` is a bit more efficient implementation of the allocation. The 
container is allocated together with the actual object.

`enable_shared_from_this` is a class you can derive from. This enables you to 
do the following:

1. Create a pointer
2. Create a smart pointer from the pointer
3. Pass the regular pointer somewhere
4. Create another smart pointer, but you actually get the same container as 
   used before.

`weak_ptr` is a smart pointer that only holds a non-owning ("weak") reference. 
It has a method lock which converts is to a temporary smart pointer. It is 
useful when things only have to be done if the data still exists.

# The C++ Object model

Source: CppCon 2015: Richard Powell “Intro to the C++ Object Model"

Non-virtual functions are determined on compile time.

Virtual functions are determined on object creation. The location of these 
functions are kept in a hidden data member called a "vtable" (virtual table). 
This hidden data member only exists if you have one or more virtual functions.

The copy constructor copies the vtable.

The constructor of a derived class first calls the constructor of the parent 
class and then overwrites its vtable.

Therefore if we call a virtual method in the constructor of the object it 
always calls the parent implementation of the virtual function, not the 
subclass'.

The vtable dramatically increases the size of small objects.

**Never call virtual functions in the constructor.**

**Don't forget to use the keyword override, when you are overriding 
functions.**

# What's a POD?

TODO: Read more about this

# RAII: Resource acquisition is initialization

TODO: Read more about this

# Operator-overloading

Most operators can be overloaded, with exception of `sizeof` (as other built in 
operations depend on it, indexing of an array for example), `::` and `.`.

Only use it when the usage is unambiguous what the operator should do.

# When should I use inline my functions?

TODO: Read more about this

# Using swap for move assignment

It also reuses code which means it increases the code readability and might 
decrease the risk of bugs. 

Downsides: Slower. Might be more than 60% slower.

[Link to longer 
discussion](http://stackoverflow.com/questions/6687388/why-do-some-people-use-swap-for-move-assignments/6687520#6687520)

# `constexpr`

There is a description of this written in one of the example exams (by me).

TODO: Move this here

# Sending arrays by reference

```{c++}
void f(int (&a)[100]) {

}

int main() {
  int i[100];

  f(i);

  return 0;
}
```

The extra parenthesis around `&a` is to keep the syntax apart from an array of 
100 int references.

# `decltype` keyword

Used to evaluate the type of a given expression at compile time. The "call" to 
`decltype` can then be used as types are normally used.

It has also one special case in function declarations, given by the lecture 
slides:

```
template<class Container>
auto end(Container& c) -> decltype(c.end())) // also for const Container&
{
  return c.end();
}
```

Where `decltype` is used to help with the type interference of `auto`. Note the 
similarity between this syntax and the syntax for lambda functions.

# Perfect forwarding

# Aggregates

> An aggregate is an array or class with no user-declared constructors, no 
> private or protected non-static data members, no base classes and no virtual 
> function.

These can be initialized using curly brackets.

# PODs

Plain old data, has two distinct properties:

1. Supports static initialization
2. Gives the same memory layout as a struct compiled in C

These requirements allows us to copy them using 

Whether a datastructure fulfills these requirements can be checked using 
`std::is_pod` defined in the header `<type_traits>`.

The formal requirement was further defined and are explained in more depth on 
[stack 
overflow](http://stackoverflow.com/questions/4178175/what-are-aggregates-and-pods-and-how-why-are-they-special/7189821#7189821)
