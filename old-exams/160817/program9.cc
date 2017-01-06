#include <vector>
#include <iterator>
#include <iostream>
#include <forward_list>

template<typename T, typename Container = std::vector<T>>
class Cycler {
    public:
        Cycler(Container& container) : container_(container) {
            reset(); 
        }

        T& next();
        void reset();
        size_t size();
    private:
        typename Container::iterator it_;
        Container container_;
};

template<typename T, typename Container>
T& Cycler<T, Container>::next() {
    if (it_ == container_.end()) {
        reset();
    }
    return *(it_++);
}

template<typename T, typename Container>
void Cycler<T, Container>::reset() {
    it_ = container_.begin();
}

int main() {
    std::vector<int> v { 1, 2, 3, 4, 5 };
    Cycler<int> c(v);

    for(int i = 0; i < 20; i++)
        std::cout << c.next() << " ";
    std::cout << std::endl;

    std::forward_list<int> ll { 1, 2, 3, 4, 5 };
    Cycler<int, std::forward_list<int>> c2(ll);

    for(int i = 0; i < 20; i++)
        std::cout << c2.next() << " ";
    std::cout << std::endl;
}
