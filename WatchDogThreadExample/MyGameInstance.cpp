#include "MyGameInstance.h"

MyGameInstance::MyGameInstance()
{
	_isRunning = false;
}


MyGameInstance::~MyGameInstance()
{
	
}

bool MyGameInstance::GetMyBoolean() const
{
	return _isRunning;
}

void MyGameInstance::SetMyBoolean(bool value)
{
	_isRunning = value;
}

void MyGameInstance::Tick()
{
	bool shouldUpdate = true;

	while (shouldUpdate)
	{
		if (!_isRunning)
		{
			// Log out successful change.
			std::cout << "Changed boolean successfully!" << std::endl;
			std::cout << std::endl;

			_isRunning = true;
		}

		//std::string data;

		//std::cin >> data;

		//if (data == "b" || data == "B")
		//{
		//	shouldUpdate = false;
		//}
	}
}