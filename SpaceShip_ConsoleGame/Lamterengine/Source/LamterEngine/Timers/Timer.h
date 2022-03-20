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
		bool updateOnDraw;

	public:
		Timer(float _maxTime, bool initReady, bool _updateOnDraw, bool activateOnStart, float startTime);

		float GetActualTime();
		float GetMaxTime();
		void ChangeMaxTime(float _maxTime);
		void Tick(float dt);
		bool IsReady();
		void Consume();
		void Stop();
		void Activate();
	};
}

