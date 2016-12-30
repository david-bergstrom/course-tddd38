#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

struct found_in {

    found_in(std::vector<int> v) : v(v) {

    }

    void operator()(int i) {
        if (std::binary_search(v.begin(), v.end(), i, std::greater<int>()))
            std::cout << i << " was found!" << std::endl;
        else
            std::cout << i << " was not found!" << std::endl;
    }

    std::vector<int> v;
};

int main() {
    std::vector<int> v { 89, 8, 6, 23 };

    std::sort(v.begin(), v.end(), std::greater<int>());

    std::for_each(std::istream_iterator<int>(std::cin), std::istream_iterator<int>(), found_in(v));

    return 0;
}
