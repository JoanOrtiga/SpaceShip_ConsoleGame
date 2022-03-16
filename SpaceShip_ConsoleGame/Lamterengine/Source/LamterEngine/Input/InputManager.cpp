#include "InputManager.h"

namespace Lamter
{
	std::map<KeyCode, bool> InputManager::lastKeysState;

	void InputManager::Init()
	{
		for (KeyCode e = KeyCode::BackSpace; e != KeyCode::INTERNAL; ++e) {
			lastKeysState.insert_or_assign(e, false);
		}
	}

	void InputManager::UpdateInput()
	{
		for (KeyCode e = KeyCode::BackSpace; e != KeyCode::INTERNAL; ++e) {
			lastKeysState[e] = IsKeyPressed(e);
		}
	}

	bool InputManager::IsKeyPressed(KeyCode keyCode)
	{
		return GetKeyState((int)keyCode) & 0x8000;
	}

	bool InputManager::IsKeyPressed(char character)
	{
		return GetKeyState(character) & 0x8000;
	}

	bool InputManager::IsKeyDown(KeyCode keyCode)
	{
		return IsKeyPressed(keyCode) && !lastKeysState[keyCode];
	}

	bool InputManager::IsKeyUp(KeyCode keyCode)
	{
		return !IsKeyPressed(keyCode) && lastKeysState[keyCode];
	}
}
