#pragma once

#include <string>

#include "Object.h"
#include "../Classes/COORD.h"
#include "Game.fwd.h"

#include "../XMLParser/ISavable.h"
#include "../XMLParser/ILoadable.h"

#include "../PreProcessor.h"

namespace Lamter
{
	class GameObject : Object , public ISavable, public ILoadable
	{
	public:
		int orderInLayer = 0;
		Lamter::COORD position = { 0,0 };
		std::string tag;
		Game* game;

	protected:
		GameObject(Game* _game);
		template <class T>
		static T* GetComponent(GameObject* gameObject);

	public:
		virtual ~GameObject() = default;
		virtual void Awake() = 0;
		virtual void NewGame() = 0;
		virtual void Update(double dt) = 0;
		virtual void DrawnUpdate() = 0;
		virtual void Draw() = 0;

		void SaveToFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode) override;
		void LoadFromFile(tinyxml2::XMLDocument* doc, tinyxml2::XMLElement* rootNode) override;
	};
}

