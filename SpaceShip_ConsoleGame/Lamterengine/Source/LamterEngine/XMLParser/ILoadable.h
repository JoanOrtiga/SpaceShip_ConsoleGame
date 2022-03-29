#pragma once

#include "../../ThirdParty/tinyxml2.h"

namespace Lamter
{
	class ILoadable
	{
	public:
		virtual ~ILoadable() = default;
		virtual void LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLNode* rootNode) = 0;
	};
}


