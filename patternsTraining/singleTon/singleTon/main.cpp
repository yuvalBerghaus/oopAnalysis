#include "Services.h"
#include <iostream>
using namespace std;
int main() {
	Services* s = Services::getInstance(3,'A');
	Services* d = Services::getInstance(0, 'A');
	cout << s->getAge()<<" and this is service d " << d->getAge();
	return 0;
}