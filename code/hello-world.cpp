#include <iostream>
#include <string>

using namespace std;


class Car
{
	public:
		Car()
		{
		}

		void drive()
		{
			cout << "Wroom wroom" << endl;
		}

	private:
		string s{};

};


int main()
{
	int x {1};

	for (int x {}; x < 10; x++)
	{
		cout << "X is " << x << endl;
	}

	cout << "Hello World" << endl;

	Car c1;
	c1.drive();
	Car * car2 = new Car();
	car2->drive();
	delete car2;
}
