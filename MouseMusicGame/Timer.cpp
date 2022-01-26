#include "Timer.h"
#include "DxLib.h"

void Timer::Update()
{
	if (isStart)
	{
		time = GetNowCount() - startTime;
	}
}

void Timer::Start()
{
	isStart = true;
	startTime = GetNowCount();
}

void Timer::Stop()
{
	isStart = false;
}

float Timer::GetNowTime()
{
	return (float)time / 1000;
}

void Timer::SetTime(float time)
{
	this->time = time;
}