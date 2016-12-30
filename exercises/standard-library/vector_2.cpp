#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

int main() {

    std::ifstream is { "cars_of_the_world.txt" };

    std::vector<std::string> cars { std::istream_iterator<std::string>(is),
        std::istream_iterator<std::string>() };

    std::sort(cars.begin(), cars.end());

    std::copy(cars.begin(), cars.end(), 
            std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
