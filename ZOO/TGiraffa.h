#pragma once
#include"TArtiodactyla.h"

const std::string GiraffaNames[4] = { "Melman", "Boris", "Peter", "Jessica" };

class TGiraffa
	: public TArtiodactyla {
public:
	TGiraffa();
	TGiraffa(const std::string & name);
	~TGiraffa() = default;
	virtual TGiraffa * BornChild();
	virtual void Live(float time) override;
};

