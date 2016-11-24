#pragma once

#include <iostream>
#include <string>

class MyGameInstance
{
public:
	MyGameInstance();
	~MyGameInstance();

	void SetMyBoolean(bool value);

	bool GetMyBoolean() const;

	void Tick();

private:

	bool _isRunning;
};

