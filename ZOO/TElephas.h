#pragma once
#include"TProboscidea.h"

const std::string ElephasNames[4] = { "Billy", "Tom", "Lans", "Karl" };

class TElephas
	: public TProboscidea {
public:
	TElephas();
	TElephas(const std::string & name);
	~TElephas() = default;
	virtual TElephas * BornChild();
	virtual void Live(float time) override;
};