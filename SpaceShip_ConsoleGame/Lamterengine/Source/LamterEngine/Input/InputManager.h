#pragma once

#include <map>
#include "KeyCode.h"

namespace Lamter
{
	class InputManager
	{
		static std::map<KeyCode, bool> lastKeysState;

	public:
		static void Init();
		static void UpdateInput();
		static bool IsKeyPressed(KeyCode keyCode);
		static bool IsKeyPressed(char s);
		static bool IsKeyDown(KeyCode keyCode);
		static bool IsKeyUp(KeyCode keyCode);
	};

	class KeyState
	{
	public:
		int key;
		bool lastState;
	};
}


