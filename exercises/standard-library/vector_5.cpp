#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>

struct lower_case {
    std::string operator()(std::string str) {
        transform(str.begin(), str.end(), str.begin(), [](char c) { return std::tolower(c); });
        return str;
    }

    typedef std::string return_type;
    typedef std::string first_argument_type;
    typedef std::string second_argument_type;
};

int main() {

    std::ifstream is { "cars_of_the_world.txt" };

    std::vector<std::string> cars { std::istream_iterator<std::string>(is),
        std::istream_iterator<std::string>() };

    std::sort(cars.begin(), cars.end());

    std::vector<std::string> lower_case_cars;

    std::transform(cars.begin(),
            cars.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"),
            lower_case());

    return 0;
}
