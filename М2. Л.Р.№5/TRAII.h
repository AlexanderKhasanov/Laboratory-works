#pragma once
#include"TNotCopyable.h"

class TRAII {
	TNotCopyable* Ptr;
public:
	TRAII()
		: Ptr(nullptr)
	{}

	TRAII(TNotCopyable* ptr)
		: Ptr(ptr) 
	{}

	~TRAII() {
		Ptr->Close();
	}
};