#include"TPair.h"
#include"TComplex.h"

int main() {
	//работа с базовым классом
	TPair pair1(1, 2);
	TPair pair2(5, 6);
	TPair pair3;
	TPair* p1 = &pair1;
	TPair* p2 = &pair2;
	TPair* p3 = &pair3;
	std::cout << "pair1=";
	p1->Print();
	std::cout << "pair2=";
	p2->Print();
	std::cout << "pair3 = pair1 + pair2=";
	p3 = &pair3;
	pair3 = pair1 + pair2;
	p3->Print();
	p3->SetFirst(10);
	p3->SetSecond(20);
	std::cout << "After changes pair1=";
	p3->Print();		
	std::cout << "\n";

	//работа с производным классом
	TComplex complex1(5, 10);
	TComplex complex2(4, 2);
	TComplex complex3;
	p1 = &complex1;
	p2 = &complex2;
	p3 = &complex3;
	std::cout << "complex1=";
	p1->Print();
	std::cout << "complex2=";
	p2->Print();
	std::cout << "complex3 = complex1 + complex2=";
	complex3 = complex1 + complex2;
	p3->Print();
	std::cout << "complex3 = complex1 - complex2=";
	complex3 = complex1 - complex2;
	p3->Print();
	std::cout << "complex3 = complex1 * complex2=";
	complex3 = complex1 * complex2;
	p3->Print();
	p3->SetFirst(1);
	p3->SetSecond(2);
	std::cout << "After changes complex1=";
	p3->Print();
	system("pause");
	return 0;
}