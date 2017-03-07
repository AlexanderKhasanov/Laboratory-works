#pragma once
#include"TCarnivora.h"

const std::string TigrisNames[4] = { "Paul", "Praskovya", "Billy", "Ksenia"};

class TTigris
	: public TCarnivora {
public:
	TTigris();
	TTigris(const std::string & name);
	~TTigris() = default;
	virtual TTigris* BornChild();
	virtual void Live(float time) override;
};