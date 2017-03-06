#include"TCircle.h"
#include"TBall.h"

int main() {
	TCircle* p;
	TCircle circle1(4.6);
	TBall ball1(2);
	p = &circle1;
	p->Print();
	p = &ball1;
	p->Print();
	system("pause");
}