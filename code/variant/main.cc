#include <iostream>
#include <variant>


// Returns either an error code or the resulting webpage
std::variant<std::string, int> get_webpage(bool t) {
    std::variant<std::string, int> result;
    
    if (t) {
        result = 404;
    } else {
        result = "Hello World";
    }

    return result;
}

int main() {

    auto website = get_webpage(true);

    if (std::holds_alternative<int>(website)) {
        std::cout << "Error: " << std::get<int>(website);
    } else {
        std::cout << "Success: " << std::get<std::string>(website);
    }
    std::cout << std::endl;
}
