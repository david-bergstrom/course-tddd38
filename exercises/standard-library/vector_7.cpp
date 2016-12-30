#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v { 89, 8, 6, 23 };

    std::sort(v.begin(), v.end(), std::greater<int>());

    int value;
    do {
        std::cin >> value;
        if (std::binary_search(v.begin(), v.end(), value, std::greater<int>()))
            std::cout << value << " was found!" << std::endl;
        else
            std::cout << value << " was not found!" << std::endl;
    } while(value != -1);

    return 0;
}
