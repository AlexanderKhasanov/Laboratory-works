#include"TGiraffa.h"

TGiraffa::TGiraffa()
	:TArtiodactyla() {
}

TGiraffa::TGiraffa(const std::string & name)
	: TArtiodactyla(name, 8, 20) {
}

TGiraffa * TGiraffa::BornChild()
{
	TGiraffa * child = new TGiraffa(GiraffaNames[rand() % 4]);
	return child;
}

void TGiraffa::Live(float time) {
	std::cout << "Giraffa ";
	if (time>=13 && time <17 || time>19 && time<22)
		std::cout << GetName() << "( Age is " << GetAge() << " days)(#"<< GetAnimalNumber()<<"):" << " is sliping" << std::endl;
	else
		TArtiodactyla::Live(time);
}