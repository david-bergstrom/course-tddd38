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

    for (auto it = cars.begin(); it != cars.end(); ++it)
        if (!it->empty() && (*it)[0] == 'B')
            std::cout << *it << std::endl;

    for (auto car : cars)
        if (!car.empty() && car[0] == 'B')
            std::cout << car << std::endl;

    return 0;
}
