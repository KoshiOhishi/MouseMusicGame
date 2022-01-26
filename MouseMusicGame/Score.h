#pragma once
#include <vector>
#include <string>
#include "Notes.h"
#include "Sound.h"

class Score
{
	template<typename T>
	using vector = std::vector<T>;
	using string = std::string;

private:
	string title;
	float bpm;
	float offset;
	vector<Notes> score;
	Sound bgm;

public:
	vector<Notes> Load(string path);
	string GetTitle();
	void PlayBGM();
	void StopBGM();
	bool isPlayBGM();
};

