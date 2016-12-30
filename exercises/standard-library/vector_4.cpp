#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>
#include <vector>


bool matches_predicate(std::string& string, std::string predicates) {
    return std::any_of(predicates.begin(), predicates.end(),
            [string] (char predicate) { return std::tolower(string[0]) == predicate; });
}

int main() {

    std::ifstream is { "cars_of_the_world.txt" };

    std::vector<std::string> cars { std::istream_iterator<std::string>(is),
        std::istream_iterator<std::string>() };

    std::sort(cars.begin(), cars.end());

    std::copy_if(cars.begin(), cars.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"),
            [](std::string& str) { return matches_predicate(str, "abc"); });

    return 0;
}
