#pragma once

namespace Lamter
{
	class Timer
	{
	private:
		float time;
		float maxTime;
		bool active;
		bool ready;

	public:
		Timer(float _maxTime, bool updateOnDraw, bool activateOnStart, float startTime);

		float GetCurrentTime();
		float GetMaxTime();
		void ChangeMaxTime(float _maxTime);
		void Tick(float dt);
		bool IsReady();
		void Stop();
		void Activate();
	};
}

