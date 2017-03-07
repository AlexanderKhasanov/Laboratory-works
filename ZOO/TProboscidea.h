#pragma once
#include"TAnimal.h"

class TProboscidea
	: public TAnimal {
public:
	const size_t ClassAnimalNumber = 2;
	TProboscidea();
	TProboscidea(const std::string& name, size_t reproductage, size_t deathAge);
	~TProboscidea() = default;
	virtual void Live(float time) override;
};