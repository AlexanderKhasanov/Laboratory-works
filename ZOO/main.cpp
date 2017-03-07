#include <thread>
#include <iostream>
#include "TZoo.h"
#include"TArtiodactyla.h"
#include"TCarnivora.h"
#include"TElephas.h"
#include"TGiraffa.h"
#include"THippopotamus.h"
#include"TLeo.h"
#include"TLoxodonta.h"
#include"TProboscidea.h"
#include"TTigris.h"

class TCat
	: public TAnimal
{
public:
	const static size_t ClassAnimalNumber = 0;

	TCat(const std::string & name)
		: TAnimal(name, 7, 14)
	{ }

	virtual TCat* BornChild() {
		TCat* child = new TCat("sema");
		return child;
	}

	virtual void Live(float time) override
	{
		// с 6 до 7 кот ест
		if (time >= 6.f && time <= 10.f)
			std::cout << GetName() << "(" << GetAge() << ")" << " is eating" << std::endl;

		// остальное время спит
		else
			std::cout << GetName() << "(" << GetAge() << ")" << " is sleeping" << std::endl;
	}
};

int main()
{	
	srand(time(NULL));
	TZoo Zoo1(20);
	TZoo Zoo2(20);
	std::string names[10] = { "Melman", "Boris", "Peter", "Jessica", "Alex", "Billy", "Tom", "Lans", "Karl", "Paul" };
	TAnimal * giraffa1 = new TGiraffa(names[rand()%11]);
	TAnimal * giraffa2 = new TGiraffa(names[rand() % 11]);

	TAnimal * hippopotamus1 = new THippopotamus(names[rand() % 11]);
	TAnimal * hippopotamus2 = new THippopotamus(names[rand() % 11]);

	TAnimal * elephas1 = new TElephas(names[rand() % 11]);
	TAnimal * elephes2 = new TElephas(names[rand() % 11]);

	TAnimal * loxodonta1 = new TLoxodonta(names[rand() % 11]);
	TAnimal * loxodonta2 = new TLoxodonta(names[rand() % 11]);

	TAnimal * leo1 = new TLeo(names[rand() % 11]);
	TAnimal * leo2 = new TLeo(names[rand() % 11]);

	TAnimal * tigris1 = new TTigris(names[rand() % 11]);
	TAnimal * tigris2 = new TTigris(names[rand() % 11]);

	Zoo1.AddNewAnimal(&giraffa1);
	Zoo1.AddNewAnimal(&giraffa2);
	Zoo1.AddNewAnimal(&hippopotamus1);
	Zoo1.AddNewAnimal(&elephas1);
	Zoo1.AddNewAnimal(&loxodonta1);
	Zoo1.AddNewAnimal(&leo1);
	Zoo1.AddNewAnimal(&leo2);
	Zoo2.AddNewAnimal(&hippopotamus2);
	Zoo2.AddNewAnimal(&elephes2);
	Zoo2.AddNewAnimal(&loxodonta2);
	Zoo2.AddNewAnimal(&tigris1);
	Zoo2.AddNewAnimal(&tigris2);
	// если не удалось добавить, то очищаем память
/*	if (!Zoo1.AddNewAnimal(&giraffa1))
		delete giraffa1;
	if (!Zoo1.AddNewAnimal(&giraffa2))
		delete giraffa2;
	if (!Zoo1.AddNewAnimal(&hippopotamus1))
		delete hippopotamus1;
	if (!Zoo2.AddNewAnimal(&hippopotamus2))
		delete hippopotamus2;
	if (!Zoo1.AddNewAnimal(&elephas1))
		delete elephas1;
	if (!Zoo2.AddNewAnimal(&elephes2))
		delete elephes2;
	if (!Zoo1.AddNewAnimal(&loxodonta1))
		delete loxodonta1;
	if (!Zoo2.AddNewAnimal(&loxodonta2))
		delete loxodonta2;
	if (!Zoo1.AddNewAnimal(&leo1))
		delete leo1;
	if (!Zoo1.AddNewAnimal(&leo2))
		delete leo2;
	if (!Zoo2.AddNewAnimal(&tigris1))
		delete tigris1;
	if (!Zoo2.AddNewAnimal(&tigris2))
		delete tigris2;*/
	size_t number = 0;
	size_t num1 = 0;
	size_t num2 = 0;
	while (true)
	{
		system("cls");
		std::cout << "Work Zoo 1: " << std::endl;
		Zoo1.Work();
		std::cout << std::endl;
		std::cout << "Work Zoo 2: " << std::endl;
		Zoo2.Work();
		if (number == 10) {
			std::cout << "Enter the number of the animal to be exchanged from the first zoo\nnum1=";
			std::cin >> num1;
			std::cout << "Enter the number of the animal to be exchanged from the second zoo\nnum2=";
			std::cin >> num2;
			ChangeAnimals(Zoo1, num1, Zoo2, num2);
		}
		(++number)%11;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	system("pause");
}