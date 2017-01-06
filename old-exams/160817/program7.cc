#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    vector<int> values { istream_iterator<int>{cin}, istream_iterator<int>{}};

    int min = *min_element(values.begin(), values.end());
    int max = *max_element(values.begin(), values.end());
    auto elements = values.size();
    int sum = accumulate(values.begin(), values.end(), 0);
    double mean = sum * 1.0 / elements;

    auto first = values.begin() + elements / 2;
    nth_element(values.begin(), first, values.end());
    auto median = static_cast<double>(*first);
   
    if (elements % 2 == 0) {
        // Even, we have two elements in the middle
        auto second = values.begin() + elements / 2;
        nth_element(values.begin(), second, values.end());
        median = (median + *second) / 2;
    } 

    // 1. Compute the difference between each value and mean
    // 2. Square each difference
    // 3. Compute the sum of the squared differences
    double diffs {};
    for_each(values.begin(), values.end(), [&diffs, mean] (int& v) { diffs += std::pow(v - mean, 2); });
    // 4. Divide the sum of the squared differences by the number of values
    // 5. The square root of this quotioent gives the population standard deviation
    auto population_std = std::sqrt(diffs / elements);

    cout << setfill('.') << left 
         << setw(18) << "min value" << ": " << min << '\n'
         << setw(18) << "max value" << ": " << max << '\n'
         << setw(18) << "mean" << ": " << mean << '\n'
         << setw(18) << "median" << ": " << median << '\n'
         << setw(18) << "standard deviation" << ": " << population_std << endl;
}
