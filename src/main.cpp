#include "Parking.hpp"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
	Parking p = Parking();
	p.deplacement(4,avant);
	p.deplacement(4,arriere);
	return 0;
}
