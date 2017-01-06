#include<type_traits>

using namespace std;

template <class T>
struct my_is_copy_assignable {
    private:
        template<class U, class = decltype(declval<U&>() = declval<U const&>()) >
        static true_type try_assignment(U&&);

        static false_type try_assignment(...);
    public:
        using type = decltype(try_assignment(declval<T>()));
};
