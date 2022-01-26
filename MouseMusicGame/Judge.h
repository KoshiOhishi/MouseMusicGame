#pragma once
#include <vector>
#include "Notes.h"
#include "Mouse.h"
#include "Timer.h"
#include "Sound.h"

class Judge
{
	template<typename T>
	using vector = std::vector<T>;

private:
	float perfect = 0.07f;
	float good = 0.13f;
	float fastslow = 0.2f;
	float miss = 0.3f;

	float score = 0;
	float addScore = 0;

	int combo = 0;
	int maxCombo = 0;
	int maxScore = 0;

	int count_p = 0;
	int count_g = 0;
	int count_fs = 0;
	int count_m = 0;

	bool isHold[6]{ false,false,false,false,false,false };

	Timer judgeTimer;
	int dispJudge = -1;
	Sound se_tap[3];
	Sound se_wheel[3];

public:
	Judge();
	void SetAddScore(int notesSize);
	void AddScore(int judge);
	void Update(vector<Notes>& score, Mouse& mouse, float nowTime, bool isAuto);
	void Judging(Notes& score, float nowTime, int type, int hold = -1);
	bool CheckJudgeNotes(int lane, char type);
	void StartDrawJudge(int judge);
	void Initialize();
	Timer GetJudgeTimer();
	int GetDispJudge();
	int GetCount_p();
	int GetCount_g();
	int GetCount_fs();
	int GetCount_m();
	int GetScore();
	int GetCombo();
	int GetMaxCombo();

};

