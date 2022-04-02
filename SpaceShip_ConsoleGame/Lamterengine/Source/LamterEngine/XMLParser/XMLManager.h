#pragma once
#include <string>

#include "../../ThirdParty/tinyxml2.h"
#include "../Structures/Game.h"

namespace Lamter
{
	class Game;

	class XMLManager
	{
	public:
		static void SaveGame(Lamter::Game* game, std::string fileLocation)
		{
			tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
			tinyxml2::XMLElement* rootNode = doc->NewElement("Root");
			doc->InsertFirstChild(rootNode);
			game->SaveToFile(doc, rootNode);
			doc->SaveFile(fileLocation.c_str());
		}

		static void LoadGame(Lamter::Game* game, std::string fileLocation)
		{
			tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();
			tinyxml2::XMLElement* rootNode = doc->FirstChildElement();
			doc->InsertFirstChild(rootNode);
			game->LoadFromFile(doc, rootNode);
			doc->SaveFile(fileLocation.c_str());
		}

		static void SaveGameObject(Lamter::GameObject* gameObject, std::string fileLocation)
		{
			tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();

			tinyxml2::XMLElement* rootNode = doc->FirstChildElement();
			if(rootNode == nullptr)
			{
				rootNode = doc->NewElement("Root");
				doc->InsertFirstChild(rootNode);
			}
			gameObject->SaveToFile(doc, rootNode);

			doc->SaveFile(fileLocation.c_str());
		}

		static void LoadGameObject(Lamter::GameObject* gameObject, std::string fileLocation)
		{
			tinyxml2::XMLDocument* doc = new tinyxml2::XMLDocument();

			if(!doc->LoadFile(fileLocation.c_str()) == tinyxml2::XML_SUCCESS)
				return;

			tinyxml2::XMLElement* rootNode = doc->FirstChildElement();
			if (rootNode == nullptr)
				return;
			gameObject->LoadFromFile(doc, rootNode);
		}
	};
}



