#pragma once

#include "../../ThirdParty/tinyxml2.h"

namespace Lamter
{
	class ISavable
	{
	public:
		virtual ~ISavable() = default;
		virtual void SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode) = 0;
	};
}

