#pragma once
#include <functional>

class DoAction
{
public:
	DoAction(std::function<void()> function = [](){}, int maximumTimes = 1, bool startLocked = false);
	~DoAction();
	void Do();
	void Reset(bool onlyIfLocked = false);
	bool GetIsLocked() const;

	std::function<void()> Function;
	int MaximumTimes;
	bool StartLocked;
	int NumberOfTimesExecuted;

private:
	bool IsLocked;
};