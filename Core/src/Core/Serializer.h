#pragma once

#include "Core/BaseDefine.h"

#include <string>

namespace Core {

	class Serializer
	{
	public:
		Serializer();

		void Serialize(const std::string& filepath);

		bool Deserialize(const std::string& filepath);
	};

}
