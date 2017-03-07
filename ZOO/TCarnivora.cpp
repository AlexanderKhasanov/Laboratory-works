#include"TCarnivora.h"

TCarnivora::TCarnivora()
	: TAnimal() {
}

TCarnivora::TCarnivora(const std::string& name, size_t reproductage, size_t deathAge)
	: TAnimal(name, reproductage, deathAge) {
}

void TCarnivora::Live(float time) {
	if ((time >= 23.f) || (time >= 0.f && time <= 11.f)) {
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is sliping" << std::endl;
	}
	else if (time > 11 && time <= 13 || time >= 20 && time < 23) {
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is eating" << std::endl;
	}
}