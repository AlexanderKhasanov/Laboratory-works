#include"TProboscidea.h"

TProboscidea::TProboscidea()
	: TAnimal() {
}

TProboscidea::TProboscidea(const std::string& name, size_t reproductage, size_t deathAge)
	: TAnimal(name, reproductage, deathAge) {
}

void TProboscidea::Live(float time) {
	if ((time >= 20.f) || (time >= 0.f && time <= 8.f))
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):"  << " is sliping" << std::endl;
	else if (time > 8 && time <= 10 || time >= 18 && time < 20) 
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):"  << " is eating" << std::endl;
}