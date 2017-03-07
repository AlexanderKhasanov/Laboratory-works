#include"TLeo.h"

TLeo::TLeo()
	:TCarnivora() {
}

TLeo::TLeo(const std::string & name)
	: TCarnivora(name, 9, 20) {
}

TLeo * TLeo::BornChild()
{
	TLeo * child = new TLeo(LeoNames[rand() % 4]);
	return child;
}

void TLeo::Live(float time) {
	std::cout << "Leo ";
	if (time > 13 && time <= 16)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is running" << std::endl;
	else if (time >= 17 && time < 20)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is walking" << std::endl;
	else
		TCarnivora::Live(time);
}