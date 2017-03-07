#include "TAnimal.h"

size_t TAnimal::Number = 0;

TAnimal::TAnimal()
	: Name()
	, Age(1)
	, ReproductAge(0)
	, DeathAge(0)
	, AnimalAlive(true)
{ }

TAnimal::TAnimal(const std::string & name, size_t reproductAge, size_t deathAge)
	: Name(name)
	, Age(1)
	, ReproductAge(reproductAge)
	, DeathAge(deathAge)
	, AnimalAlive(true)
	, AnimalNumber(++Number)
{ }

std::string TAnimal::GetName() const{
	return Name;
}

size_t TAnimal::GetAge() const{
	return Age;
}

size_t TAnimal::GetReproductAge() const {
	return ReproductAge;
}

size_t TAnimal::GetDeathAge() const {
	return DeathAge;
}

size_t TAnimal::GetAnimalNumber() const {
	return AnimalNumber;
}

bool TAnimal::GetAnimalAlive() const{
	return AnimalAlive;
}

bool TAnimal::PossibilityChild() const {
	if (AnimalAlive && Age >= ReproductAge && Age <= DeathAge&&rand()%10==0)
		return true;
	else return false;
}

void TAnimal::AddDays() {
	if (AnimalAlive) {
		++Age;
		if (Age >= DeathAge)
			AnimalAlive = false;
	}
}
