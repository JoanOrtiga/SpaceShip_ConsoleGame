#include "Time.h"

#include <Windows.h>


namespace Lamter {

    Time::Time(int targetFPS)
    {
        FPS = targetFPS;
        deltaSeconds = 1.0 / FPS;
	    const auto currentTime = std::chrono::system_clock::now();
        lastTime = currentTime;
        nextTime = currentTime - lastTime;
    }

    bool Time::ShouldDrawNextFrame(bool& normalUpdate)
    {
	    const std::chrono::duration<double> currentTime = std::chrono::system_clock::now() - lastTime;

        if ((currentTime - nextTime).count() > maxTimeDiff)
        {
            nextTime = currentTime;
        }

        if (currentTime >= nextTime)
        {
            normalUpdate = true;

            const auto cDeltaSeconds = static_cast<std::chrono::duration<double>>(deltaSeconds);
            nextTime += cDeltaSeconds;

            if ((currentTime < nextTime) || (skippedFrames > maxSkippedFrames))
            {
                skippedFrames = 1;
                return true;
            }
            else
            {
                skippedFrames++;
            }
        }
        else
        {
            normalUpdate = false;

	        const int sleepTime = (int)(1000.0 * (nextTime - currentTime).count());
            if (sleepTime > 0)
            {
                Sleep(sleepTime);
            }
        }

        return false;
    }

}

