#include <iostream>
#include <vector>

#include "vector.hpp"
#include "particle.hpp"

int main() {
	std::cout << "Particle Simulation II" << std::endl;

	Vector v1 = Vector();
	std::cout << sizeof(v1) << " bytes" << std::endl;

	Vector v2 = Vector({0, 1, 2}, {3, 4, 5}, {6, 7, 8});
	std::cout << sizeof(v2) << " bytes" << std::endl;

	Particle p1 = Particle();
	std::cout << sizeof(p1) << " bytes" << std::endl;

	Particle p2 = Particle("Baryon", -1, "?", 1.67e-27, 1.6e-19, 0, 1); // proton
	std::cout << sizeof(p2) << " bytes" << std::endl;

	
	return 0;
};
