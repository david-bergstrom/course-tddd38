#include <algorithm>
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T, T min, T max>
class Modular
{
    public:
        explicit Modular(T const&);

        Modular<T, min, max>& operator=(T const&);
        T operator++();
        T operator++(int);

        template<T rmin, T rmax>
        Modular<T, min, max> operator+(Modular<T, rmin, rmax> const&);

        operator T() const;

    private:
        T value_;
        void assign(T const&);
};

template<typename T, T min, T max>
Modular<T, min, max>::Modular(T const& t) {
    if (min < t && t < max) {
        value_ = t;
    } else {
        value_ = min;
    }
}

template<typename T, T min, T max>
Modular<T, min, max>& Modular<T, min, max>::operator=(T const& t)
{
    if (min < t && t < max) {
        value_ = t;
    } else {
        throw std::domain_error("Assigned value " 
                + to_string(t) + " to modular out of range (" 
                + to_string(min) + ", " + to_string(max) + ").");
    }
    return *this;
}

template<typename T, T min, T max>
T Modular<T, min, max>::operator++()
{ 
    if (value_ == max) {
        value_ = min;
    } else {
        value_++;
    }

    return value_;
}

template<typename T, T min, T max>
T Modular<T, min, max>::operator++(int)
{ 
    // Store previous value
    int previous = value_;

    // Increment
    if (value_ == max) {
        value_ = min;
    } else {
        value_++;
    }

    // Return previous value
    return previous;
}

template<typename T, T min, T max>
template<T rmin, T rmax>
Modular<T, min, max>
Modular<T, min, max>::operator+(Modular<T, rmin, rmax> const& rhs) {
    T temp_value = value_ + rhs;

    cout << "temp_value" << temp_value << endl;

    while (temp_value > max) {
        temp_value -= (max - min);
    }

    cout << "temp_value after first while: " << temp_value << endl;

    while (temp_value < min) {
        temp_value += (max - min);
    }

    cout << "temp_value after second while: " << temp_value << endl;
    
    return Modular<T, min, max>(temp_value);
}


template<typename T, T min, T max>
Modular<T, min, max>::operator T() const {
    return value_;
}

int main()
{
    Modular<int, 2, 10> m{3};
    cout << m << endl; // Prints 3
    try
    {
        m = 1;
    }
    catch ( std::domain_error const & e)
    {
        cout << e.what() << endl; // Prints error
    }
    Modular<int, 2,10> m2 {5};
    m = m + m2;
    cout << m << endl; // Print 8
    m = m + Modular<int,-11,-2>{-10}; // Runs 8 - 10, using ints?
    cout << "Should be 7: " << m << endl;
    cout << "Should print 7 9: " << m++ << " ";
    cout << ++m;
    Modular<char,'a','c'> mc{'b'};
    ++mc;
    cout << "\nShould print a: " << ++mc << endl;
}
