#include "Core/Serializer.h"

#include "Core/Log.h"

#include <fstream>
#include <yaml-cpp/yaml.h>

namespace Core {

	struct TestInfo
	{
		std::string name;
		unsigned int size;
		float value;
	};

	Serializer::Serializer()
	{

	}

	void Serializer::Serialize(const std::string& filepath)
	{
		std::vector<TestInfo> testInfo;
		std::string info(" Ver 0.20");
		testInfo.push_back({"test01", 16, 1.0f });
		testInfo.push_back({"test02", 32, 0.5f });

		YAML::Emitter out;
		out << YAML::BeginMap;
		out << YAML::Key << "Core" << YAML::Value << info.c_str();
		out << YAML::Key << "TestInfo" << YAML::BeginSeq;
		for (auto info : testInfo)
		{
			out << YAML::BeginMap;
			out << YAML::Key << "Name" << YAML::Value << info.name;
			out << YAML::Key << "Size" << YAML::Value << info.size;
			out << YAML::Key << "Value" << YAML::Value << info.value;
			out << YAML::EndMap;
		}		
		out << YAML::EndSeq;
		out << YAML::Newline;
		out << YAML::EndMap;

		std::ofstream fout(filepath);
		fout << out.c_str();
	}

	bool Serializer::Deserialize(const std::string& filepath)
	{
		YAML::Node data;
		try
		{
			data = YAML::LoadFile(filepath);
		}
		catch (YAML::ParserException e)
		{
			CORE_ERROR("Failed to load .hazel file '{0}'\n     {1}", filepath, e.what());
			return false;
		}

		if (!data["Core"])
			return false;

		std::vector<TestInfo> testInfo;
		auto testinfos = data["TestInfo"];
		if (testinfos)
		{
			for (auto info : testinfos)
			{
				TestInfo t;
				t.name = info["Name"].as<std::string>();
				t.size = info["Size"].as<unsigned int>();
				t.value = info["Value"].as<float>();
				testInfo.push_back(t);
			}
		}
		return true;
	}

}