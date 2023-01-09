#include <iostream>

#include "Header.h"

int main()
{
	Core::Log::Init();

	APP_INFO("Console Application");

	int t = 5;
	APP_TRACE("t = {0}", t);

	std::cin.get();
}