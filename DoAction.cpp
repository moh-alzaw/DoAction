#include "DoAction.h"

DoAction::DoAction(std::function<void()> function, int maximumTimes, bool startLocked)
{
    StartLocked = startLocked;
    IsLocked = startLocked;
    MaximumTimes = maximumTimes;
    Function = function;
    NumberOfTimesExecuted = 0;
}

DoAction::~DoAction()
{
}

void DoAction::Do()
{
    if (IsLocked)
        return;

    NumberOfTimesExecuted++;
    if (MaximumTimes >= NumberOfTimesExecuted)
    {
        IsLocked = true;
    }
    Function();
}

void DoAction::Reset(bool onlyIfLocked)
{
    if (onlyIfLocked && !IsLocked)
        return;

    NumberOfTimesExecuted = 0;
    IsLocked = StartLocked;
}

bool DoAction::GetIsLocked() const
{
    return IsLocked;
}