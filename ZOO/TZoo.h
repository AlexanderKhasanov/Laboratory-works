#pragma once
#include "TAnimal.h"

const float STEP = 1;

class TZoo
{
	typedef TAnimal * TPtrAnimal;


	/// �����
	TPtrAnimal * Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	float Time;
public:
	TZoo();
	TZoo(size_t capacity);
	size_t GetNumAnimals() const;
	float GetTime() const;
	bool BornAnimal();
	bool DeathAnimal();
	bool AddNewAnimal(TAnimal ** newAnimal);
	bool DeleteAnimal(size_t numberAnimal);
	void Work();
	~TZoo();
	friend void ChangeAnimals(TZoo & zoo1, size_t num1, TZoo & zoo2, size_t num2);
};

void ChangeAnimals(TZoo & zoo1, size_t num1, TZoo & zoo2, size_t num2);