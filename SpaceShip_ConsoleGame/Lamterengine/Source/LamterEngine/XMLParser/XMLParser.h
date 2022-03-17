#pragma once
#include <string>

#include "../../ThirdParty/tinyxml2.h"

class XMLParser
{
public:
	template <class T>
	static void SaveObject(T t, std::string fileLocation)
	{
		int x = 5;
		tinyxml2::XMLDocument doc;
		doc.LoadFile(fileLocation.c_str());
	}
};

class data
{
	int x;
	int y;
};

void x()
{
	data t;
	XMLParser::SaveObject(t, "");
}
