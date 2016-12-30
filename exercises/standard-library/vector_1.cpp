#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct alphabet_generator {
    char letter = 'a';

    char operator()() {
        return letter++;
    }
};

int main() {
    vector<char> alphabet;
    alphabet_generator generator;

    generate_n(back_inserter(alphabet),
            26, generator);

    copy(alphabet.begin(), alphabet.end(), 
            ostream_iterator<char>(std::cout, " "));

    cout << endl;

    copy(alphabet.rbegin(), alphabet.rend(), 
            ostream_iterator<char>(std::cout, " "));

    return 0;
}
