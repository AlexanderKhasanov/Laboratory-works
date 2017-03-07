#include "TZoo.h"

TZoo::TZoo()
	: Capacity(0)
	, NumAnimals(0)
	, Time(0)
	, Animals(nullptr)
{}

TZoo::TZoo(size_t capacity)
	: Capacity(capacity)
	, NumAnimals(0)
	, Time(0)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}

size_t TZoo::GetNumAnimals() const {
	return NumAnimals;
}

float TZoo::GetTime() const {
	return Time;
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
} 



bool TZoo::DeleteAnimal(size_t numberAnimals) {
	for (int i = 0; i < NumAnimals; ++i) {
		if (Animals[i]->GetAnimalNumber() == numberAnimals) {
			delete Animals[i];
			for (int j = i; j < NumAnimals-1; ++j) {
				Animals[j] = Animals[j + 1];
			}
			--NumAnimals;
			return true;
		}
	}
	return false;
}

bool TZoo::BornAnimal() {
	for (int i = 0; i < NumAnimals-1; ++i) {
		for (int j = i + 1; j < NumAnimals; ++j) {
			if (Animals[i]->ClassAnimalNumber == Animals[j]->ClassAnimalNumber&&Animals[i]->PossibilityChild()&&Animals[j]->PossibilityChild()) {
				TAnimal* clield = Animals[i]->BornChild();
				AddNewAnimal(&clield);
			//	++NumAnimals;
				return true;
			}
		}
	}
	return false;
}

bool TZoo::DeathAnimal() {
	for (int i = 0; i < NumAnimals; ++i) {
		if (Animals[i]->GetAge() >= Animals[i]->GetDeathAge()) {
			delete Animals[i];
			for (int j = i; j < NumAnimals; ++j) {
				Animals[j] = Animals[j + 1];
			}
			--NumAnimals;
			return true;
		}
	}
	return false;
}

void TZoo::Work(){
	bool newDay = false;
	Time += STEP;
	if (Time > 24.f) {
		Time -= 24.f;
		newDay = true;
	}
	std::cout << "Time: " << Time << std::endl << std::endl;
	if (NumAnimals == 0) 
		std::cout << "RIP" << std::endl;
	else {
		int newChilde = 0;
		if (BornAnimal())
			newChilde = 1;
		for (int i = 0; i < NumAnimals - newChilde; ++i) {
			if (newDay)
				Animals[i]->AddDays();
		}
	}
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr)
			// Демонстрация работы динамического полиморфизма
			Animals[i]->Live(Time);
		DeathAnimal();
	}
}


TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}


void ChangeAnimals(TZoo & zoo1, size_t num1, TZoo & zoo2, size_t num2) {
	size_t n1 = 0;
	size_t n2 = 0;
	for (n1 = 0; n1 < zoo1.NumAnimals; ++n1) {
		if (zoo1.Animals[n1]->GetAnimalNumber() == num1)
			break;
	}
	for (n2 = 0; n2 < zoo1.NumAnimals; ++n2) {
		if (zoo1.Animals[n2]->GetAnimalNumber() == num1)
			break;
	}
	zoo1.AddNewAnimal(&zoo2.Animals[n2]);
	zoo2.AddNewAnimal(&zoo1.Animals[n1]);
	zoo1.DeleteAnimal(n1);
	zoo2.DeleteAnimal(n2);
}