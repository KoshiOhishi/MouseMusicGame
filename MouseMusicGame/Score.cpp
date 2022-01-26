#include "Score.h"
#include "DxLib.h"

std::vector<Notes> Score::Load(string path)
{
	int fileHandle = FileRead_open(path.c_str());
	bool readNotes = false;
	int measure = 0;

	while (FileRead_eof(fileHandle) == 0)
	{
		char read[256];
		FileRead_gets(read, 256, fileHandle);

		string strRead = string(read);

		//譜面情報読み込み
		if (strRead.find("TITLE:") != string::npos)
			title = strRead.substr(6);

		if (strRead.find("BPM:") != string::npos)
			bpm = (float)atof(strRead.substr(4).c_str());

		if (strRead.find("BGMPASS:") != string::npos)
			bgm.LoadSound(strRead.substr(8).c_str());

		if (strRead.find("BGMVOLUME:") != string::npos)
			bgm.SetVolume(atoi(strRead.substr(10).c_str()));

		if (strRead.find("OFFSET:") != string::npos)
			offset = (float)atof(strRead.substr(7).c_str());

		if (strRead.find("#START") != string::npos)
		{
			readNotes = true;
			continue;
		}

		if (strRead.find("#END") != string::npos)
		{
			readNotes = false;
			continue;
		}

		//譜面内容読み込み
		/*
		1～6	通常タップ
		a～f	ホールド始点
		A～F	ホールド終点
		+,-		左ホイール
		<.>		右ホイール
		
		*/
		if (readNotes)
		{
			string strCount = strRead;
			int sub = 0;
			while (strCount.find('(') != string::npos)
			{
				sub += strCount.find_first_of(')') - strCount.find_first_of('(');
				strCount = strCount.substr(strCount.find_first_of(')') + 1);
			}

			int count = strRead.size() - 1 - sub;	//セミコロン

			int letterCount = 0;
			bool isDouble = false;	//同時判定
			for (int i = 0; i < strRead.size(); i++)
			{
				if (strRead.substr(i, 1) == "0")
				{
					letterCount++;
					continue;
				}
				if (strRead.substr(i, 1) == ";") break;


				if (strRead.substr(i, 1) == "(")
				{
					isDouble = true;
					continue;
				}

				if (strRead.substr(i, 1) == ")")
				{
					isDouble = false;
					letterCount++;
					continue;
				}

				score.push_back(Notes(strRead.substr(i, 1).at(0), ((float)measure * 240.0f / bpm + (float)letterCount / count * 240.0f / bpm) + offset));

				if (!isDouble)
					letterCount++;
			}

			measure++;
		}

		//ホールドの結び付け設定
		for (int i = 0; i < score.size(); i++)
		{
			if (score[i].GetNotesType() == 'a')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'A')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

			if (score[i].GetNotesType() == 'b')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'B')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

			if (score[i].GetNotesType() == 'c')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'C')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

			if (score[i].GetNotesType() == 'd')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'D')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

			if (score[i].GetNotesType() == 'e')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'E')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

			if (score[i].GetNotesType() == 'f')
			{
				for (int j = i; j < score.size(); j++)
				{
					if (score[j].GetNotesType() == 'F')
					{
						score[i].SetHoldSync(j);
						break;
					}
				}
			}

		}

	}
	FileRead_close(fileHandle);

	return score;
}

void Score::PlayBGM()
{
	bgm.Play();
}

void Score::StopBGM()
{
	bgm.Stop();
}

std::string Score::GetTitle()
{
	return title;
}

bool Score::isPlayBGM()
{
	return bgm.isPlayNow();
}