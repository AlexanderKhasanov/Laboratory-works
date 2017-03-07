#include"TArtiodactyla.h"

TArtiodactyla::TArtiodactyla() 
	:TAnimal(){
}

TArtiodactyla::TArtiodactyla(const std::string& name, size_t reproductage, size_t deathAge) 
	: TAnimal(name, reproductage, deathAge) {
}

void TArtiodactyla::Live(float time) {
	if ((time >= 22.f) || (time >= 0.f && time <= 10.f)) {
		std::cout<< GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is sliping" << std::endl;
	}
	else if (time > 10 && time <= 12 || time>=17 && time<=19) {
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#" << GetAnimalNumber() << "):" << " is eating" << std::endl;
	}
}
