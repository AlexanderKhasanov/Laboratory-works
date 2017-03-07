#include"TElephas.h"

TElephas::TElephas()
	:TProboscidea() {
}

TElephas::TElephas(const std::string & name)
	: TProboscidea(name, 10, 20) {
}

TElephas * TElephas::BornChild()
{
	TElephas * child = new TElephas(ElephasNames[rand() % 4]);
	return child;
}

void TElephas::Live(float time) {
	std::cout << "Elephas ";
	if (time > 10 && time < 13 || time>15 && time < 18) 
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is walking" << std::endl;
	else if (time >= 13 && time <= 15)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is washing" << std::endl;
	else
		TProboscidea::Live(time);
}