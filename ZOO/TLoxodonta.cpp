#include"TLoxodonta.h"

TLoxodonta::TLoxodonta()
	:TProboscidea() {
}

TLoxodonta::TLoxodonta(const std::string & name)
	: TProboscidea(name, 7, 15) {
}


TLoxodonta * TLoxodonta::BornChild()
{
	TLoxodonta * child = new TLoxodonta(LoxodontaNames[rand() % 4]);
	return child;
}
void TLoxodonta::Live(float time) {
	std::cout << "Loxodonta ";
	if (time > 10 && time < 13 || time>15 && time < 18)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is walking" << std::endl;
	else if (time >= 13 && time <= 15)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is drinkøòï" << std::endl;
	else
		TProboscidea::Live(time);
}