#pragma once
#include"TCarnivora.h"

const std::string LeoNames[4] = { "Alex", "LeBron", "Michael", "Anastasia"};

class TLeo
	: public TCarnivora {
public:
	TLeo();
	TLeo(const std::string & name);
	~TLeo() = default;
	virtual TLeo* BornChild();
	virtual void Live(float time) override;
};