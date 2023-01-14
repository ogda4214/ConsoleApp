#include <iostream>

#include "Header.h"
#include "Core/Serializer.h"

int main()
{
	Core::Log::Init();

	{
		Core::Serializer serializer;
		serializer.Serialize("app.config");
	}

	APP_INFO("Console Application");

	int t = 5;
	//CORE_ASSERT(t < 3);
	APP_TRACE("t = {0}", t);

	{
		Core::Serializer serializer;
		serializer.Deserialize("app.config");
	}

	std::cin.get();
}