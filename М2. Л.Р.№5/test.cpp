#include "TNotCopyable.h"
#include"TRAII.h"
#include <iostream>

int main()
{
	try
	{
		TNotCopyable obj;
		TRAII ptr(&obj);
		obj.OpenToWrite("someFile.txt");

		obj.OpenToRead("someOtherFile.txt");

		obj.Close();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what()<<std::endl;
	}
} 