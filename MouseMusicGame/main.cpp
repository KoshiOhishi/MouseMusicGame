#include <vector>
#include "DxLib.h" 
#include "Input.h"
#include "Mouse.h"
#include "Scene.h"
#include "Draw.h"
#include "Timer.h"
#include "Score.h"
#include "Judge.h"

using namespace std;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	const char TITLE[] = "MouseMusicGame";
	const int WIN_WIDTH = 1280, WIN_HEIGHT = 720;

	//�E�B���h�E���[�h�ɐݒ� 
	ChangeWindowMode(TRUE);

	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A 
	//���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ��� 
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	//�^�C�g����ύX
	SetMainWindowText(TITLE);

	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32); //32�͌Œ�

	//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetWindowSizeExtendRate(1.0);

	//��ʂ̔w�i�F��ݒ�
	SetBackgroundColor(31, 31, 31);

	//Dx���C�u������������ 
	if (DxLib_Init() == -1)
	{
		//�G���[���o����}�C�i�X�l��Ԃ��ďI�� 
		return -1;
	}

	////�����������܂őҋ@ 
	//WaitKey();
	Input input;
	Mouse mouse;
	Scene scene;
	Draw draw;
	bool isAuto = false;
	Timer timer;
	Score ls;
	Judge judge;
	vector<Notes> score = ls.Load("Resource/test.mmg");
	int fontHandle = CreateFontToHandle(NULL, 32, -1, DX_FONTTYPE_NORMAL);
	SetDrawScreen(DX_SCREEN_BACK);
	while (1)
	{
		ClearDrawScreen();
		//�����ɏ���������

		input.Update();
		mouse.Update();

		if (scene.GetNowScene() == "Title")
		{
			if (input.IsTrigger(KEY_INPUT_SPACE))
			{
				timer.Start();
				draw.LoadScore(score);
				ls.PlayBGM();
				judge.SetAddScore(score.size());
				scene.SetScene("Game");
			}

			if (input.IsTrigger(KEY_INPUT_F1))
				isAuto = !isAuto;

			draw.DrawAll(timer.GetNowTime(), mouse, judge.GetJudgeTimer(), judge.GetDispJudge(), judge.GetCombo());

			DrawFormatStringToHandle(500, 500, GetColor(255, 255, 255), fontHandle, "%s", "PRESS SPACE KEY");

			if (isAuto)
				DrawFormatString(0, 0, GetColor(255, 255, 255), "%s\n\n%d\n\nAUTO:%s", ls.GetTitle().c_str(), judge.GetScore(), "ON");
			else
				DrawFormatString(0, 0, GetColor(255, 255, 255), "%s\n\n%d\n\nAUTO:%s", ls.GetTitle().c_str(), judge.GetScore(), "OFF");

			if (input.IsTrigger(KEY_INPUT_ESCAPE)) break;

		}
		else if (scene.GetNowScene() == "Game")
		{
			timer.Update();

			judge.Update(score, mouse, timer.GetNowTime(), isAuto);

			draw.UpdateJudge(score);

			draw.DrawAll(timer.GetNowTime(), mouse, judge.GetJudgeTimer(), judge.GetDispJudge(), judge.GetCombo());

			if (isAuto)
				DrawFormatString(0, 0, GetColor(255, 255, 255), "%s\n\n%d\n\nAUTO:%s", ls.GetTitle().c_str(), judge.GetScore(), "ON");
			else
				DrawFormatString(0, 0, GetColor(255, 255, 255), "%s\n\n%d\n\nAUTO:%s", ls.GetTitle().c_str(), judge.GetScore(), "OFF");

			if (!ls.isPlayBGM())
				scene.SetScene("Result");

			if (input.IsTrigger(KEY_INPUT_ESCAPE))
			{
				ls.StopBGM();
				scene.SetScene("Result");
			}

		}
		else if (scene.GetNowScene() == "Result")
		{
			DrawFormatStringToHandle(500, 100, GetColor(255, 255, 255), fontHandle,"SCORE:%d\n\nPERFECT:%d\n\nGOOD:%d\n\nFAST/SLOW:%d\n\nMISS:%d\n\nMAXCOMBO:%d", judge.GetScore(), judge.GetCount_p(), judge.GetCount_g(), judge.GetCount_fs(), judge.GetCount_m(), judge.GetMaxCombo());

			DrawFormatStringToHandle(500, 550, GetColor(255, 255, 255), fontHandle, "%s", "PRESS SPACE KEY");

			if (input.IsTrigger(KEY_INPUT_SPACE))
			{
				judge.Initialize();
				for (int i = 0; i < score.size(); i++)
					score[i].Initialize();
				timer.SetTime(0);

				scene.SetScene("Title");
			}

			if (input.IsTrigger(KEY_INPUT_ESCAPE)) break;
		}



		ScreenFlip();

		if (ProcessMessage() == -1) break;
	}

	//Dx���C�u�����I������ 
	DxLib_End();

	return 0;

}

