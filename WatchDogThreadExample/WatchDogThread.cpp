#include "WatchDogThread.h"

WatchDogThread::WatchDogThread(MyGameInstance& gameInstance)
{
	_myGameInstance = &gameInstance;


	_interval = 30;

	_timer = 0;

	_isRunning = true;

	_numberOfAttempts = 0;

	// Log out successful launch of watch dog thread.
	std::cout << "Watch dog thread initiated." << std::endl;
	std::cout << std::endl;

	_thread = std::thread(&WatchDogThread::Loop, this);
}

WatchDogThread::~WatchDogThread()
{

}

void WatchDogThread::Loop()
{
	// Log out that the thread is now performing checks on the game instance.
	std::cout << "Watch dog thread entering loop function to check on game instance!" << std::endl;
	std::cout << std::endl;


	while (_isRunning)
	{
		if (_myGameInstance->GetMyBoolean())
		{
			// Log out successful change.
			std::cout << "Watch dog thread has succesfully swapped boolean." << std::endl;
			std::cout << std::endl;

			_myGameInstance->SetMyBoolean(false);
		}
		else
		{
			if (_numberOfAttempts >= 3)
			{
				_isRunning = false;

				Stop();
			}

			// Log out unsuccessful check.
			std::cout << "Watch dog thread has not detected a change in the boolean." << std::endl;
			std::cout << std::endl;

			_numberOfAttempts++;

			// Log out number of attempts.
			std::cout << "Number of attempts so far: " << _numberOfAttempts << std::endl;
			std::cout << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}
}

void WatchDogThread::Stop()
{
	if (_myGameInstance->GetMyBoolean())
	{
		_myGameInstance->SetMyBoolean(false);
		//_isRunning = false;
	}

	_thread.detach();
}
