#pragma once

#include "LamterEngine/Structures/GameObject.h"
#include "LamterEngine/Timers/Timer.h"

class Explosion : public Lamter::GameObject
{
private:
	static constexpr short maxStates = 4;
	static constexpr short explosionSizeX = 3;
	static constexpr short explosionSizeY = 3;
	const char explosionShape[maxStates][explosionSizeX][explosionSizeY] =
	{
		{
			/*
			{' ', ' ', ' '},
			{' ', 'O', ' '},
			{' ', ' ', ' '}
			*/
			{32,32,32},
			{32,111,32},
			{32,32,32}
		},
		{
			/*
			{'\\', '|', '/'},
			{'-', 'O', '-'},
			{'/', '|', '\\'}
			*/
			{92,124,47},
			{45,111,45},
			{47,124,92}
		},
		{
			/*
			{'\\', '|', '/'},
			{'-', ' ', '-'},
			{'/', '|', '\\'}
			*/
			{92,124,47},
			{45,32,45},
			{47,124,92}
		},
		{
			/*
			{' ', ' ', ' '},
			{' ', ' ', ' '},
			{' ', ' ', ' '}
			*/
			{32,32,32},
			{32,32,32},
			{32,32,32}
		}
	 
	};
	short currentState = -1;

	Lamter::Timer* movingTimer;
	float movementSpeed = 0.15;


public:
	Explosion(Lamter::COORD spawnPosition, Lamter::Game* _game);
	~Explosion() override;

	void Awake() override;
	void NewGame() override;
	void Update(double dt) override;
	void DrawnUpdate() override;
	void Draw() override;
};

