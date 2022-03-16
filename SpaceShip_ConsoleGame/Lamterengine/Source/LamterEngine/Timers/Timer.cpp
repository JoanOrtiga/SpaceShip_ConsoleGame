#include "Timer.h"

namespace Lamter
{
	Timer::Timer(float _maxTime, bool updateOnDraw, bool activateOnStart = true, float startTime = -1)
	{
		if (startTime < 0)
			time = _maxTime;
		else
			time = 0;

		maxTime = _maxTime;
		active = activateOnStart;
		ready = false;
	}

	void Timer::Tick(float dt)
	{
		if (active)
		{
			time -= dt;
			if(time <= 0)
			{
				time = maxTime;
				ready = true;
			}
		}
	}

	bool Timer::IsReady()
	{
		if(ready)
		{
			time = maxTime;
			ready = false;
			return true;
		}

		return false;
	}

	float Timer::GetCurrentTime()
	{
		return time;
	}

	float Timer::GetMaxTime()
	{
		return maxTime;
	}

	void Timer::ChangeMaxTime(float _maxTime)
	{
		maxTime = _maxTime;
	}

	void Timer::Stop()
	{
		active = false;
	}

	void Timer::Activate()
	{
		active = true;
	}
}
