#pragma once
class IMenu
{
public:
	virtual ~IMenu() = default;
	virtual bool ExitGame() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

