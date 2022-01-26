#pragma once
#include <vector>
#include <unordered_map>
#include "Notes.h"
#include "Mouse.h"
#include "Timer.h"

class Draw
{
	template<typename T>
	using vector = std::vector<T>;
	template<typename T1, typename T2>
	using unordered_map = std::unordered_map<T1, T2>;

private:
	int fontHandle;
	int comboFontHandle;
	int tick = 20;
	int speed = 500;
	int tex_notes_tap;
	int tex_notes_hold;
	int tex_notes_hold_inside;
	int tex_notes_flick_up;
	int tex_notes_flick_down;
	vector<Notes> score;

public:
	Draw();
	void LoadScore(vector<Notes> score);
	void DrawMain(Mouse mouse);
	void DrawNotes(char notesType, float notesTime, float nowTime);
	void DrawHoldInside(float nowTime);
	void DrawJudge(Timer judgeTimer, int judge);
	void DrawAll(float nowTime, Mouse mouse, Timer judgeTimer, int judge, int combo);
	void UpdateJudge(vector<Notes>& score);
	void DrawCombo(int combo);
};

