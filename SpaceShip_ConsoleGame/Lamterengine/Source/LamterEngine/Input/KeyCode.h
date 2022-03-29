#pragma once

#include <stdexcept>
#include <Windows.h>

namespace Lamter
{
	enum class KeyCode : uint8_t
	{
		None = 0,
		BackSpace = 8,
		Tab = 9,
		Return = 13,
		Escape = 27,
		SpaceBar = 32,
		UpArrow = WM_KEYUP,
		DownArrow = WM_KEYDOWN,

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83, 
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,
			
		Delete = 127,
		INTERNAL = 500
	};

	inline KeyCode& operator ++ (KeyCode& e)
	{
		if (e == KeyCode::INTERNAL) {
			throw std::out_of_range("for E& operator ++ (E&)");
		}
		e = KeyCode(static_cast<std::underlying_type<KeyCode>::type>(e) + 1);
		return e;
	}
}

