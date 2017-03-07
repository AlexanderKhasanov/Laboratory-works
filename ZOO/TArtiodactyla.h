#pragma once
#include"TAnimal.h"

class TArtiodactyla 
	: public TAnimal {
public:
	const size_t ClassAnimalNumber = 1;
	TArtiodactyla();
	TArtiodactyla(const std::string& name, size_t reproductage, size_t deathAge);
	virtual ~TArtiodactyla() = default;
	virtual void Live(float time) override;
};