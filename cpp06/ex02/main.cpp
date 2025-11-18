#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

Base* generate(void) {
	int	random_class = std::rand() % 3;

	switch (random_class) {
	case 0:
		cout << "Returning Class A object" << endl;
		return new A();
	case 1:
		cout << "Returning Class B object" << endl;
		return new B();
	case 2:
		cout << "Returning Class C object" << endl;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base* p) {
	cout << "Identifying class type using pointer..." << endl;

	if (dynamic_cast<A*>(p) != NULL)
		cout << "Object Class: A" << endl;
	else if (dynamic_cast<B*>(p) != NULL)
		cout << "Object Class: B" << endl;
	else if (dynamic_cast<C*>(p) != NULL)
		cout << "Object Class: C" << endl;
	else
		cout << "UTO 👽 (Unknown Type of Object)" << endl;
}

void identify(Base& p) {
	cout << "Identifying class type using reference..." << endl;

	Base* pointer = &p;
	identify(pointer);
}

int	main(void) {
	std::srand(std::time(NULL));

	cout << "\n--- Testing different identification functions ---\n" << endl;

	for (int i = 0; i < 5; i++) {

		Base* random_type = generate();

		if (!random_type)
			return 1;
		
		cout << endl;
		cout << "Testing pointer identifier: " << endl;
		identify(random_type);
		cout << endl;
		cout << "Testing reference identifier: " << endl;
		identify(*random_type);

		cout << " ---------- " << endl;
	}
	return 0;
}