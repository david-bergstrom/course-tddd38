#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template<typename T>
void my_sort_heap(std::vector<T>& v) {
    // order the contents as a max-heap
    std::make_heap(v.begin(), v.end());

    for (auto it = v.end(); it != v.begin(); --it) {
        // swap the first and last element in the remaining part of the vector
        std::pop_heap(v.begin(), it);
    }
}

template<typename T>
void print_vector(std::vector<T> v) {
    std::copy(v.begin(), v.end(),
           std::ostream_iterator<T>(std::cout, " "));
    std::cout << std::endl;
}

int main() {

    std::vector<int> v { 1, 2, 3, 4, 5 };
    my_sort_heap(v);
    print_vector(v);

    std::vector<std::string> v2 { "the", "lazy", "fox", "etc" };
    my_sort_heap(v2);
    print_vector(v2);

    return 0;
}
