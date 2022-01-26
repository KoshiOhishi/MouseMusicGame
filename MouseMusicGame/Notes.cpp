#include "Notes.h"

Notes::Notes(char notesType, float notesTime)
{
	this->notesType = notesType;
	this->notesTime = notesTime;
}


char Notes::GetNotesType()
{
	return notesType;
}

float Notes::GetNotesTime()
{
	return notesTime;
}

void Notes::SetJudge(int judge)
{
	this->judge = judge;
}

int Notes::GetJudge()
{
	return judge;
}

int Notes::GetHoldSync()
{
	return holdSync;
}

void Notes::SetHoldSync(int holdSync)
{
	this->holdSync = holdSync;
}

void Notes::Initialize()
{
	judge = -1;
}