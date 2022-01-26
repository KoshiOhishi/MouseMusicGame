#pragma once

class Notes
{
private:
	char notesType = '\0';		//ノーツの種類
	float notesTime = 0;	//ノーツの判定時間
	int judge = -1;		//ノーツの判定 0...perfect 1...good 2...fast 3...slow 4...miss
	int holdSync = -1;	//ホールドを結び付けるために使用

public:

	Notes(char notesType, float notesTime);

	char GetNotesType();
	float GetNotesTime();
	int GetJudge();
	int GetHoldSync();

	void SetJudge(int judge);
	void SetHoldSync(int holdSync);
	void Initialize();
};

