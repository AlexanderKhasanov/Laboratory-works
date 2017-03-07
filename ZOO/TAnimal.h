#pragma once
#include <string>
#include<iostream>

class TAnimal
{
	std::string Name;//��� ���������
	size_t Age;//�������
	size_t ReproductAge;//�������, � �������� ������ ������
	size_t DeathAge;//������� ��� ������� �������
	size_t AnimalNumber;//����� ���������
	static size_t Number;//��� ������� ������ ���������
	bool AnimalAlive;//���� ������������ ���� �� ��������

public:
	const size_t ClassAnimalNumber = 0;
	TAnimal();
	TAnimal(const std::string & name, size_t reproductAge, size_t deathAge);

	/// ���������� ���������� �� ���������.
	/// �.�. ����������� �������� ��� ������� �������� �� ���������
	virtual ~TAnimal() = default;

	/// ����������� �����
	/// <param name="time"> ����� ����� </param>
	virtual void Live(float time) = 0;

	virtual TAnimal* BornChild() = 0;
	std::string GetName() const;
	size_t GetAge() const;
	size_t GetReproductAge() const;
	size_t GetDeathAge() const;
	size_t GetAnimalNumber() const;
	bool GetAnimalAlive() const;
	bool PossibilityChild() const;//����������, ����� �� �������� ������
	void AddDays();
};
