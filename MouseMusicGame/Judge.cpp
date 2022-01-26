#include "Judge.h"
#include "DxLib.h"

Judge::Judge()
{
	se_tap[0].LoadSound("Resource/tap.ogg");
	se_tap[1].LoadSound("Resource/tap_fs.ogg");
	se_tap[2].LoadSound("Resource/tap_miss.ogg");

	se_wheel[0].LoadSound("Resource/wheel.ogg");
	se_wheel[1].LoadSound("Resource/wheel_fs.ogg");
	se_wheel[2].LoadSound("Resource/wheel_miss.ogg");

}

void Judge::SetAddScore(int notesSize)
{
	addScore = 1000000.0f / notesSize;
	maxScore = notesSize;
}

void Judge::Update(vector<Notes>& score, Mouse& mouse, float nowTime, bool isAuto)
{
	if (!isAuto)
	{
		//レーンごとに判定をとる
		for (int lane = 0; lane < 6; lane++)
		{

			for (int i = 0; i < score.size(); i++)
			{
				//
				if (!CheckJudgeNotes(lane, score[i].GetNotesType())) continue;
				if (score[i].GetJudge() >= 0) continue;
				//ホールド終点はミス範囲前での処理も必要

#pragma region 後ろミス判定
				if (score[i].GetNotesTime() - nowTime < -miss)
				{
					count_m++;
					score[i].SetJudge(4);
					StartDrawJudge(4);
					if (maxCombo < combo)
						maxCombo = combo;
					combo = 0;

#pragma region ホールド無視
					if (score[i].GetNotesType() == 'a')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'A')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}
					else if (score[i].GetNotesType() == 'b')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'B')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}
					else if (score[i].GetNotesType() == 'c')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'C')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}
					else if (score[i].GetNotesType() == 'd')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'D')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}
					else if (score[i].GetNotesType() == 'e')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'E')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}
					else if (score[i].GetNotesType() == 'f')
					{
						for (int j = i; j < score.size(); j++)
						{
							if (score[j].GetNotesType() == 'F')
							{
								count_m++;
								score[j].SetJudge(4);
								StartDrawJudge(4);
								if (maxCombo < combo)
									maxCombo = combo;
								combo = 0;
								break;
							}
						}
					}

#pragma endregion

					continue;
				}
#pragma endregion

				
				if (score[i].GetNotesTime() - nowTime <= miss)	//判定範囲以前の時はホールド終点以外処理を飛ばす
				{

#pragma region 通常タップ

					if (mouse.IsTrigger(MOUSE_INPUT_LEFT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == '1')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

					if (mouse.IsTrigger(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == '2')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

					if (mouse.IsTrigger(MOUSE_INPUT_RIGHT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == '3')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

					if (mouse.IsTrigger(MOUSE_INPUT_LEFT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == '4')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

					if (mouse.IsTrigger(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() > 640 && score[i].GetNotesType() == '5')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

					if (mouse.IsTrigger(MOUSE_INPUT_RIGHT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == '6')
					{
						Judging(score[i], nowTime, 0);
						break;
					}

#pragma endregion

#pragma region ホールド始点

					else if (mouse.IsTrigger(MOUSE_INPUT_LEFT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'a')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

					else if (mouse.IsTrigger(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'b')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

					else if (mouse.IsTrigger(MOUSE_INPUT_RIGHT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'c')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

					else if (mouse.IsTrigger(MOUSE_INPUT_LEFT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'd')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

					else if (mouse.IsTrigger(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'e')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

					else if (mouse.IsTrigger(MOUSE_INPUT_RIGHT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'f')
					{
						Judging(score[i], nowTime, 0, lane);
						break;
					}

#pragma endregion

#pragma region ホイール

					else if (mouse.isWheelMoving() == 1 && mouse.GetPosX() <= 640 && score[i].GetNotesType() == '+')
					{
						Judging(score[i], nowTime, 1);
						break;
					}

					else if (mouse.isWheelMoving() == 2 && mouse.GetPosX() <= 640 && score[i].GetNotesType() == '-')
					{
						Judging(score[i], nowTime, 1);
						break;
					}

					else if (mouse.isWheelMoving() == 1 && mouse.GetPosX() > 640 && score[i].GetNotesType() == '<')
					{
						Judging(score[i], nowTime, 1);
						break;
					}

					else if (mouse.isWheelMoving() == 2 && mouse.GetPosX() > 640 && score[i].GetNotesType() == '>')
					{
						Judging(score[i], nowTime, 1);
						break;
					}

#pragma endregion

				}

#pragma region ホールド終点

				if (isHold[0] && !mouse.IsPush(MOUSE_INPUT_LEFT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'A')
				{
					Judging(score[i], nowTime, 0, lane);
					break;

				}

				else if (isHold[1] && !mouse.IsPush(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'B')
				{
					Judging(score[i], nowTime, 0, lane);
					break;
				}

				else if (isHold[2] && !mouse.IsPush(MOUSE_INPUT_RIGHT) && mouse.GetPosX() <= 640 && score[i].GetNotesType() == 'C')
				{
					Judging(score[i], nowTime, 0, lane);
					break;
				}

				else if (isHold[3] && !mouse.IsPush(MOUSE_INPUT_LEFT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'D')
				{
					Judging(score[i], nowTime, 0, lane);
					break;
				}

				else if (isHold[4] && !mouse.IsPush(MOUSE_INPUT_MIDDLE) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'E')
				{
					Judging(score[i], nowTime, 0, lane);
					break;
				}

				else if (isHold[5] && !mouse.IsPush(MOUSE_INPUT_RIGHT) && mouse.GetPosX() > 640 && score[i].GetNotesType() == 'F')
				{
					Judging(score[i], nowTime, 0, lane);
					break;
				}

#pragma endregion
			}
		}
	}
	else
	{
		for (int i = 0; i < score.size(); i++)
		{
			if (score[i].GetJudge() >= 0) continue;
			if (score[i].GetNotesTime() - nowTime > miss) continue;

			if (score[i].GetNotesTime() - nowTime < 0)
			{
				if (score[i].GetNotesType() == '1' || score[i].GetNotesType() == '2' || score[i].GetNotesType() == '3' ||
					score[i].GetNotesType() == 'a' || score[i].GetNotesType() == 'b' || score[i].GetNotesType() == 'c' ||
					score[i].GetNotesType() == 'A' || score[i].GetNotesType() == 'B' || score[i].GetNotesType() == 'C' ||
					score[i].GetNotesType() == '+' || score[i].GetNotesType() == '-')
				{
						mouse.SetMousePoint(320, 360);
				}
				else
				{
						mouse.SetMousePoint(1280 - 320, 360);
				}

				count_p++;
				score[i].SetJudge(0);
				StartDrawJudge(0);
				AddScore(0);
				combo++;
				if (maxCombo < combo)
					maxCombo = combo;
				if (score[i].GetNotesType() != '+' && score[i].GetNotesType() != '-' && score[i].GetNotesType() != '<' && score[i].GetNotesType() != '>')
					se_tap[0].Play();
				else
					se_wheel[0].Play();

				continue;
			}
		}
	}

	judgeTimer.Update();
	if (judgeTimer.GetNowTime() >= 0.4f)
	{
		judgeTimer.Stop();
		judgeTimer.SetTime(0);
		dispJudge = -1;
	}
}

void Judge::StartDrawJudge(int judge)
{
	judgeTimer.SetTime(0);
	judgeTimer.Start();
	dispJudge = judge;
}

Timer Judge::GetJudgeTimer()
{
	return judgeTimer;
}

int Judge::GetDispJudge()
{
	return dispJudge;
}

void Judge::Judging(Notes& score, float nowTime, int type, int hold)
{
	int judge = -1;

	if (type != 1 && score.GetNotesTime() - nowTime > fastslow)
	{
		judge = 4;		//Miss
	}
	else if (type != 1 && score.GetNotesTime() - nowTime > good)
	{
		judge = 2;		//Fast
	}
	else if (score.GetNotesTime() - nowTime > perfect)
	{
		judge = 1;		//Good
	}
	else if (score.GetNotesTime() - nowTime >= -perfect)
	{
		judge = 0;		//Perfect
	}
	else if (score.GetNotesTime() - nowTime >= -good)
	{
		judge = 1;		//Good
	}
	else if (score.GetNotesTime() - nowTime >= -fastslow)
	{
		judge = 3;		//Slow
	}

	if (judge == 0)
	{
		count_p++;
		score.SetJudge(0);
		StartDrawJudge(0);
		AddScore(0);
		combo++;
		if (maxCombo < combo)
			maxCombo = combo;
		if (type == 0)
			se_tap[0].Play();
		else if (type == 1)
			se_wheel[0].Play();
		if (hold != -1)
			isHold[hold] = !isHold[hold];
	}
	else if (judge == 1)
	{
		count_g++;
		score.SetJudge(1);
		StartDrawJudge(1);
		AddScore(1);
		combo++;
		if (maxCombo < combo)
			maxCombo = combo;
		if (type == 0)
			se_tap[0].Play();
		else if (type == 1)
			se_wheel[0].Play();
		if (hold != -1)
			isHold[hold] = !isHold[hold];
	}
	else if (judge == 2)
	{
		count_fs++;
		score.SetJudge(2);
		StartDrawJudge(2);
		AddScore(2);
		if (maxCombo < combo)
			maxCombo = combo;
		combo = 0;
		if (type == 0)
			se_tap[1].Play();
		else if (type == 1)
			se_wheel[1].Play();
		if (hold != -1)
			isHold[hold] = !isHold[hold];
	}
	else if (judge == 3)
	{
		count_fs++;
		score.SetJudge(3);
		StartDrawJudge(3);
		AddScore(3);
		if (maxCombo < combo)
			maxCombo = combo;
		combo = 0;
		if (type == 0)
			se_tap[1].Play();
		else if (type == 1)
			se_wheel[1].Play();
		if (hold != -1)
			isHold[hold] = !isHold[hold];
	}
	else if (judge == 4)
	{
		count_m++;
		score.SetJudge(4);
		StartDrawJudge(4);
		AddScore(4);	//一応
		if (maxCombo < combo)
			maxCombo = combo;
		combo = 0;
		if (type == 0)
			se_tap[2].Play();
		else if (type == 1)
			se_wheel[2].Play();
		if (hold != -1)
			isHold[hold] = !isHold[hold];
	}

}

bool Judge::CheckJudgeNotes(int lane, char type)
{
	if (lane == 0 && (type == '1' || type == 'a' || type == 'A'))
		return true;
	if (lane == 1 && (type == '2' || type == 'b' || type == 'B' || type == '+' || type == '-'))
		return true;
	if (lane == 2 && (type == '3' || type == 'c' || type == 'C'))
		return true;
	if (lane == 3 && (type == '4' || type == 'd' || type == 'D'))
		return true;
	if (lane == 4 && (type == '5' || type == 'e' || type == 'E' || type == '<' || type == '>'))
		return true;
	if (lane == 5 && (type == '6' || type == 'f' || type == 'F'))
		return true;

	return false;

}

void Judge::AddScore(int judge)
{
	if (judge == 0)
		score += addScore;
	else if (judge == 1)
		score += addScore / 2;
	else if (judge == 2 || judge == 3)
		score += addScore / 3;

	if (count_p == maxScore) score = 1000000;	//理論値は100万
}

void Judge::Initialize()
{
	count_p = 0;
	count_g = 0;
	count_fs = 0;
	count_m = 0;

	judgeTimer.SetTime(0);
	for (int i = 0; i < 6; i++)
		isHold[i] = false;

	dispJudge = -1;
	score = 0;
	addScore = 0;
	combo = 0;
}

int Judge::GetCount_p()
{
	return count_p;
}
int Judge::GetCount_g()
{
	return count_g;
}
int Judge::GetCount_fs()
{
	return count_fs;
}
int Judge::GetCount_m()
{
	return count_m;
}

int Judge::GetScore()
{
	return score;
}

int Judge::GetCombo()
{
	return combo;
}

int Judge::GetMaxCombo()
{
	return maxCombo;
}

