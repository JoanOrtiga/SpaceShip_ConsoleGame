#include "SpaceshipMenu.h"

#include "LamterEngine/Console/ConsoleController.h"
#include "LamterEngine/Input/InputManager.h"

SpaceshipMenu::SpaceshipMenu(Lamter::Game* _game): Menu(_game)
{
}

SpaceshipMenu::~SpaceshipMenu()
{
}

void SpaceshipMenu::Update()
{
	if(Lamter::InputManager::IsKeyDown(Lamter::KeyCode::Escape))
	{
		Menu::Quit();
	}
	else if(Lamter::InputManager::IsKeyDown(Lamter::KeyCode::C))
	{
		Menu::NewGame();
	}
}

void SpaceshipMenu::Draw()
{

}

void SpaceshipMenu::InitialDraw()
{
	Lamter::ConsoleController::CLS();

	Lamter::ConsoleController::SetConsoleColor(Lamter::Color::RED);
	Lamter::ConsoleController::DrawAt("Game Lost", Lamter::ConsoleController::GetConsoleBufferSize().x / 2 - 4, Lamter::ConsoleController::GetConsoleBufferSize().y / 2-2);
	Lamter::ConsoleController::SetConsoleColor(Lamter::Color::WHITE);

	std::string exitMessage = "Press button 'C' to continue, or ESC, to close";
	Lamter::ConsoleController::DrawAt(exitMessage, Lamter::ConsoleController::GetConsoleBufferSize().x / 2 - exitMessage.length() / 2, Lamter::ConsoleController::GetConsoleBufferSize().y / 2);
}
