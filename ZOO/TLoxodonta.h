#pragma once
#include"TProboscidea.h"

const std::string LoxodontaNames[4] = { "Sema", "Vanya", "Evdokinia", "Lev"};

class TLoxodonta
	: public TProboscidea {
public:
	TLoxodonta();
	TLoxodonta(const std::string & name);
	~TLoxodonta() = default;
	virtual TLoxodonta * BornChild();
	virtual void Live(float time) override;
};