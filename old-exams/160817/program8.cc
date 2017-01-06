#include <iostream>
#include <sstream>
#include <string>

class Hexadecimal {
	public:
		template<typename T>
		static std::string convert(const T& t) {
			std::stringstream ss;
			ss << std::hex << t;
			return ss.str();
		}
};

class Quoted {
	public:
		template<typename T>
		static std::string convert(const T& t) {
			std::stringstream ss;
			ss << '\"' << t << '\"';
			return ss.str();
		}
};

template<typename T, typename Policy>
class Wrapper
{
public:
	Wrapper(const T value) : value_(value) {}
	void set(const T value) { value_ = value; }
	T get() const { return value_; };
	std::string str() const;
private:
	T value_;
};

template<typename T, typename Policy>
std::string Wrapper<T, Policy>::str() const {
	return Policy::convert(value_);
}


int main() {
	Wrapper<int, Hexadecimal> w { 10 };
	std::cout << w.str() << std::endl;
	Wrapper<int, Quoted> w1 { 10 };
	std::cout << w1.str() << std::endl;

	Wrapper<long long, Hexadecimal> w2 { 1000000000 };
	std::cout << w2.str() << std::endl;

	Wrapper<std::string, Quoted> hello { "hello world" };
	std::cout << hello.str() << std::endl;
}
