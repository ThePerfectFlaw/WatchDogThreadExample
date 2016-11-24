#pragma once

#include <thread>
#include <atomic>
#include "MyGameInstance.h"

class WatchDogThread
{
public:

	// Constructor, taking in the game instance to perform checks and functions upon it.
	WatchDogThread(MyGameInstance& gameInstance);
	~WatchDogThread();

	// Start function.
	void Start(unsigned int milliseconds, std::function<void()> callback);

	void Stop();

	// Determines whether the thread is running or not.
	std::atomic<bool> _isRunning;

private:

	// Function to loop our thread.
	void Loop();

	// The faked game instance.
	MyGameInstance* _myGameInstance;

	// 
	std::function<void()> _callback;

	// The interval.
	unsigned int _interval;

	// Number of attempts made.
	unsigned int _numberOfAttempts;

	// The timer.
	std::atomic<unsigned int> _timer;

	// The thread created to run this task.
	std::thread _thread;
};

