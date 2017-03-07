#include"TTigris.h"

TTigris::TTigris()
	:TCarnivora() {
}

TTigris::TTigris(const std::string & name)
	: TCarnivora(name, 9, 20) {
}

TTigris * TTigris::BornChild()
{
	TTigris * child = new TTigris(TigrisNames[rand() % 4]);
	return child;
}

void TTigris::Live(float time) {
	std::cout << "Tigris ";
	if (time > 13 && time <= 16)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is playing" << std::endl;
	else if (time >= 17 && time < 20)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is running" << std::endl;
	else
		TCarnivora::Live(time);
}