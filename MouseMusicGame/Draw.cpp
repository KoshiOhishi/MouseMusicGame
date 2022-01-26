#include "Draw.h"
#include "DxLib.h"
using namespace std;

Draw::Draw()
{
	tex_notes_tap = LoadGraph("Resource/notes_tap.png");
	tex_notes_hold = LoadGraph("Resource/notes_hold.png");
	tex_notes_hold_inside = LoadGraph("Resource/notes_hold_inside.png");
	tex_notes_flick_up = LoadGraph("Resource/notes_flick_up.png");
	tex_notes_flick_down = LoadGraph("Resource/notes_flick_down.png");


	fontHandle = CreateFontToHandle(NULL, 32, -1, DX_FONTTYPE_NORMAL);
	comboFontHandle = CreateFontToHandle(NULL, 100, -1, DX_FONTTYPE_NORMAL);
}

void Draw::LoadScore(vector<Notes> score)
{
	this->score = score;
}

void Draw::DrawMain(Mouse mouse)
{
	DrawBox(256, 0, 1024, 720, GetColor(63, 63, 63), TRUE);

	//カーソルに応じて光るやつ
	if (mouse.GetPosX() >= 0 && mouse.GetPosX() <= 1280)
	{
		if (mouse.GetPosX() <= 640)
			DrawBox(256, 0, 640, 720, GetColor(128, 128, 128), TRUE);
		else if (mouse.GetPosX() <= 1280)
			DrawBox(640, 0, 1024, 720, GetColor(128, 128, 128), TRUE);
	}

	//押したら光るやつ
	if (mouse.GetPosX() >= 0 && mouse.GetPosX() <= 1280)
	{
		if (mouse.GetPosX() <= 640)
		{
			if (mouse.IsPush(MOUSE_INPUT_LEFT))
			{
				DrawBox(256, 0, 256 + 128 * 1, 720, GetColor(192, 192, 192), TRUE);
			}
			if (mouse.IsPush(MOUSE_INPUT_MIDDLE))
			{
				DrawBox(256 + 128 * 1, 0, 256 + 128 * 2, 720, GetColor(192, 192, 192), TRUE);
			}
			if (mouse.IsPush(MOUSE_INPUT_RIGHT))
			{
				DrawBox(256 + 128 * 2, 0, 256 + 128 * 3, 720, GetColor(192, 192, 192), TRUE);
			}

			//回したら光るやつ
			if (mouse.isWheelMoving() == 1)
				DrawBox(256 + 128 * 1, 0, 256 + 128 * 2, 720, GetColor(192, 192, 255), TRUE);
			if (mouse.isWheelMoving() == 2)
				DrawBox(256 + 128 * 1, 0, 256 + 128 * 2, 720, GetColor(192, 255, 192), TRUE);

		}
		else if (mouse.GetPosX() <= 1280)
		{
			if (mouse.IsPush(MOUSE_INPUT_LEFT))
			{
				DrawBox(256 + 128 * 3, 0, 256 + 128 * 4, 720, GetColor(192, 192, 192), TRUE);
			}
			if (mouse.IsPush(MOUSE_INPUT_MIDDLE))
			{
				DrawBox(256 + 128 * 4, 0, 256 + 128 * 5, 720, GetColor(192, 192, 192), TRUE);
			}
			if (mouse.IsPush(MOUSE_INPUT_RIGHT))
			{
				DrawBox(256 + 128 * 5, 0, 256 + 128 * 6, 720, GetColor(192, 192, 192), TRUE);
			}
			//回したら光るやつ
			if (mouse.isWheelMoving() == 1)
				DrawBox(256 + 128 * 4, 0, 256 + 128 * 5, 720, GetColor(192, 192, 255), TRUE);
			if (mouse.isWheelMoving() == 2)
				DrawBox(256 + 128 * 4, 0, 256 + 128 * 5, 720, GetColor(192, 255, 192), TRUE);

		}


	}





	//メインの3本
	for (int i = 0; i < 3; i++)
	{
		DrawLine(256 + 384 * i, 0, 256 + 384 * i, 720, 0, 5);
	}

	//分割線
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			DrawLine(256 + 384 * i + 128 * j, 0, 256 + 384 * i + 128 * j, 720, 0, 3);
		}
	}

	//判定ライン
	DrawLine(256, 600, 1024, 600, GetColor(255, 128, 128), 5);

}

void Draw::DrawNotes(char notesType, float notesTime, float nowTime)
{

	//通常タップ
	if (notesType == '1')
		DrawGraph(256 + 0 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);
	else if (notesType == '2')
		DrawGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);
	else if (notesType == '3')
		DrawGraph(256 + 2 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);
	else if (notesType == '4')
		DrawGraph(256 + 3 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);
	else if (notesType == '5')
		DrawGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);
	else if (notesType == '6')
		DrawGraph(256 + 5 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_tap, TRUE);


	//ホールド
	else if (notesType == 'a')
		DrawGraph(256 + 0 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'b')
		DrawGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'c')
		DrawGraph(256 + 2 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'd')
		DrawGraph(256 + 3 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'e')
		DrawGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'f')
		DrawGraph(256 + 5 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);

	//ホールド終点
	else if (notesType == 'A')
		DrawGraph(256 + 0 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'B')
		DrawGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'C')
		DrawGraph(256 + 2 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'D')
		DrawGraph(256 + 3 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'E')
		DrawGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);
	else if (notesType == 'F')
		DrawGraph(256 + 5 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_hold, TRUE);

	//ホイール
	else if (notesType == '+')
		DrawGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_flick_up, TRUE);
	else if (notesType == '-')
		DrawGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_flick_down, TRUE);
	else if (notesType == '<')
		DrawGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_flick_up, TRUE);
	else if (notesType == '>')
		DrawGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - notesTime) * speed, tex_notes_flick_down, TRUE);


}

void Draw::DrawHoldInside(float nowTime)
{
	for (int i = 0; i < score.size(); i++)
	{
		if (score[i].GetHoldSync() == -1) continue;

		if (score[score[i].GetHoldSync()].GetJudge() == -1)
		{
			if (score[i].GetJudge() >= 0)
			{
				if (score[i].GetNotesType() == 'a')
				{
					DrawExtendGraph(256 + 0 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 0 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'b')
				{
					DrawExtendGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 1 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'c')
				{
					DrawExtendGraph(256 + 2 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 2 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'd')
				{
					DrawExtendGraph(256 + 3 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 3 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'e')
				{
					DrawExtendGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 4 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'f')
				{
					DrawExtendGraph(256 + 5 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 5 * 128 + 128, 600, tex_notes_hold_inside, TRUE);
				}
			}
			else
			{
				if (score[i].GetNotesType() == 'a')
				{
					DrawExtendGraph(256 + 0 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 0 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'b')
				{
					DrawExtendGraph(256 + 1 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 1 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'c')
				{
					DrawExtendGraph(256 + 2 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 2 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'd')
				{
					DrawExtendGraph(256 + 3 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 3 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'e')
				{
					DrawExtendGraph(256 + 4 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 4 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
				else if (score[i].GetNotesType() == 'f')
				{
					DrawExtendGraph(256 + 5 * 128, 600 - tick / 2 + (nowTime - score[score[i].GetHoldSync()].GetNotesTime()) * speed, 256 + 5 * 128 + 128, 600 - tick / 2 + (nowTime - score[i].GetNotesTime()) * speed, tex_notes_hold_inside, TRUE);
				}
			}
		}
	}
}

void Draw::DrawJudge(Timer judgeTimer, int judge)
{
	
	if (judgeTimer.GetNowTime() > 0)
	{
		//640-
		if (judge == 0)
			DrawStringToHandle(640 - 32 * 2, 550, "PERFECT", GetColor(255, 255, 255),fontHandle);
		if (judge == 1)
			DrawStringToHandle(640 - 32 * 1, 550, "GOOD", GetColor(255, 255, 255), fontHandle);
		if (judge == 2)
			DrawStringToHandle(640 - 32 * 1, 550, "FAST", GetColor(255, 255, 255), fontHandle);
		if (judge == 3)
			DrawStringToHandle(640 - 32 * 1, 550, "SLOW", GetColor(255, 255, 255), fontHandle);
		if (judge == 4)
			DrawStringToHandle(640 - 32 * 1, 550, "MISS", GetColor(255, 255, 255), fontHandle);

	}
}

void Draw::DrawAll(float nowTime, Mouse mouse, Timer judgeTimer, int judge, int combo)
{
	DrawMain(mouse);
	DrawCombo(combo);
	//ホールド中間
	DrawHoldInside(nowTime);

	for (int i = 0; i < score.size(); i++)
	{
		if (score[i].GetJudge() == -1)
		DrawNotes(score[i].GetNotesType(), score[i].GetNotesTime(), nowTime);
	}

	//判定
	DrawJudge(judgeTimer, judge);
}

void Draw::UpdateJudge(vector<Notes>& score)
{
	for (int i = 0; i < score.size(); i++)
	{
		this->score[i].SetJudge(score[i].GetJudge());
	}
}

void Draw::DrawCombo(int combo)
{
	int keta = 0;
	int math = combo;
	while (math != 0)
	{
		math = math / 10;
		keta++;
	}
	if (keta != 0 && combo >= 5)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 192);
		DrawFormatStringToHandle(640 - keta * 25, 260, GetColor(255, 255, 255), comboFontHandle, "%d", combo);
		DrawFormatStringToHandle(510, 365, GetColor(255, 255, 255), comboFontHandle, "%s", "COMBO");
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
}
