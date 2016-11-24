#pragma once

#include "MyGameInstance.h"
#include "WatchDogThread.h"

int main()
{
	MyGameInstance* gameInstance = new MyGameInstance();

	WatchDogThread wdt(*gameInstance);

	bool running = true;

	while (running)
	{
		gameInstance->Tick();

		if (!wdt._isRunning)
		{
			running = false;
		}
	}

	return 0;
}