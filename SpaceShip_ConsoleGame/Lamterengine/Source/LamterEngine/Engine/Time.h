#pragma once

#include <chrono>

namespace Lamter {

	class Time
	{
	public:
		double deltaSeconds = 1.0 / FPS;

	private:
		std::chrono::system_clock::time_point lastTime{};
		std::chrono::duration<double> nextTime{};

		const double maxTimeDiff = 5;

		int FPS = 60;

		int skippedFrames = 0;
		const int maxSkippedFrames = 5;

	public:
		Time(int targetFPS);
		bool ShouldDrawNextFrame(bool& normalUpdate);
	};
}
