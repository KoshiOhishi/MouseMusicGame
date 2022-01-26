#pragma once
class Timer
{
private:
	int time = 0;
	int startTime = 0;
	bool isStart;

public:
	void Update();
	void Start();
	void Stop();
	float GetNowTime();
	void SetTime(float time);
};

