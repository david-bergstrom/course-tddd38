class Class1 {
	public:
		Class1(int x) { }
};

class Class2 {
	public:
		// Without the initializing list here, the example won't compile
		Class2() : c1 {3} { }
	private:
		Class1 c1;
};

int main() {

}
