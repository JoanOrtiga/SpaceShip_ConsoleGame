#pragma once

#include <string>
#include <Windows.h>

#include "Color.h"
#include "../Classes/COORD.h"

namespace Lamter
{
	class ConsoleController
	{
		static COORD consolePixelSize;
		static COORD consoleBufferSize;

		static HANDLE stdHandle;
		static CONSOLE_SCREEN_BUFFER_INFO csbi;

	public:
		ConsoleController() = delete;

		static void Init(COORD _consoleBufferSize, bool showCursor);
		static void SetCursorVisible(bool visibility);
		static void Delete();

		static void CLS();
		static void DrawAt(char character, COORD position);
		static void DrawAt(std::string text, COORD position);
		static void Draw(char character);
		static void Draw(std::string text);
		static void DrawAt(char character, int x, int y);
		static void DrawAt(std::string text, int x, int y);
		static void Fill(char character, int fillAmount);

		static void SetCursorPosition(int x, int y);
		static void SetCursorPosition(COORD position);

		static void SetConsoleColor(Color color);

		static COORD GetConsoleBufferSize();

	private:
		static void GetWindowPos(int* x, int* y);
		static void GetWindowSize(int* x, int* y);

		static void SetConsoleSize(int width, int heigh);
		static bool HasConsoleChangedSize();
	};
}
