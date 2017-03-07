#pragma once
#include <string>
#include<iostream>

class TAnimal
{
	std::string Name;//им€ животного
	size_t Age;//возраст
	size_t ReproductAge;//возраст, с которого можжет родить
	size_t DeathAge;//возраст при котором умирает
	size_t AnimalNumber;//номер животного
	static size_t Number;//дл€ задани€ номера животного
	bool AnimalAlive;//флаг определ€ющий живо ли животное

public:
	const size_t ClassAnimalNumber = 0;
	TAnimal();
	TAnimal(const std::string & name, size_t reproductAge, size_t deathAge);

	/// »спользуем деструктор по умолчанию.
	/// т.к. специальных действи€ дл€ очистки объектов не требуетс€
	virtual ~TAnimal() = default;

	/// јбстрактный метод
	/// <param name="time"> ¬рем€ суток </param>
	virtual void Live(float time) = 0;

	virtual TAnimal* BornChild() = 0;
	std::string GetName() const;
	size_t GetAge() const;
	size_t GetReproductAge() const;
	size_t GetDeathAge() const;
	size_t GetAnimalNumber() const;
	bool GetAnimalAlive() const;
	bool PossibilityChild() const;//определ€ет, может ли животное родить
	void AddDays();
};
