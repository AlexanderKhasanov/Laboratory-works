#pragma once
#include"TArtiodactyla.h"

const std::string HippopotamusNames[4] = { "Gloria", "Bob", "Shaggy", "Basie" };

class THippopotamus
	: public TArtiodactyla {
public:
	THippopotamus();
	THippopotamus(const std::string & name);
	~THippopotamus() = default;
	virtual THippopotamus * BornChild();
	virtual void Live(float) override;
};