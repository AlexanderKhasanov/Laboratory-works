#include"THippopotamus.h"

THippopotamus::THippopotamus()
	:TArtiodactyla() {
}

THippopotamus::THippopotamus(const std::string &name)
	: TArtiodactyla(name, 7, 20){
}

THippopotamus * THippopotamus::BornChild()
{
	THippopotamus * child = new THippopotamus(HippopotamusNames[rand() % 4]);
	return child;
}

void THippopotamus::Live(float time) {
	std::cout << "Hippopotamus ";
	if (time>=13 && time <17 || time>19 && time<22)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is swimming" << std::endl;
	else
		TArtiodactyla::Live(time);
}