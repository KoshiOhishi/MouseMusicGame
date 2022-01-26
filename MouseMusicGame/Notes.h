#pragma once

class Notes
{
private:
	char notesType = '\0';		//�m�[�c�̎��
	float notesTime = 0;	//�m�[�c�̔��莞��
	int judge = -1;		//�m�[�c�̔��� 0...perfect 1...good 2...fast 3...slow 4...miss
	int holdSync = -1;	//�z�[���h�����ѕt���邽�߂Ɏg�p

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

