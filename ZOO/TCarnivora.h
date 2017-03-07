#pragma once
#include"TAnimal.h"

class TCarnivora
	: public TAnimal {
public:
	const size_t ClassAnimalNumber = 3;
	TCarnivora();
	TCarnivora(const std::string& name, size_t reproductage, size_t deathAge);
	~TCarnivora() = default;
	virtual void Live(float time) override;
};