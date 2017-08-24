# 1.

Given code:

```{
template <typename T>
T max(T, T);

int i;
double d;
```

Calling `max(i, d)` does not match any template. The template max only matches 
when the two operands are of the same type. A way to to make it work is to use 
a cast in the call, making the call: max(static_cast<double>(i), d);

# 2.

Unnamed namespaces can be used for having private functions or data. The 
contents of a unnamed namespace cannot be accessed outside of the file where 
they where defined.

# 3.

Mutable can be used when defining lambda functions to specify that is is 
allowed to change its captured variables.

Mutable can be used when declaring a non-static, non-const, non-reference 
member to make it possible to change that member withing a const-expression for 
instance inside a const-declared member function or on a const object.

# 4.

class T {
  T(U) { ...} // converting from U to T via a constructor
  operator U() { } // conversion operator, from T to U.
};

# 5. 

A delegating constructor is a constructor which calls another constructor 
inside the same class. The call must be in the member initializer list.
