#include "Timer.h"

namespace Lamter
{
	Timer::Timer(float _maxTime, bool initReady, bool _updateOnDraw, bool activateOnStart = true, float startTime = -1)
	{
		if (startTime < 0)
			time = _maxTime;
		else
			time = 0;

		maxTime = _maxTime;
		active = activateOnStart;
		ready = initReady;
		updateOnDraw = _updateOnDraw;
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
		if(updateOnDraw)
		{
			if (ready)
			{
				ready = false;
				return true;
			}
			return false;
		}

		return ready;
	}

	void Timer::Consume()
	{
		ready = false;
	}

	float Timer::GetActualTime()
	{
		return time;
	}

	float Timer::GetCountUpTime()
	{
		return maxTime - time;
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

	void Timer::Reset()
	{
		time = maxTime;
		ready = false;
	}
}
