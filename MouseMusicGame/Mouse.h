#pragma once

class Mouse
{
private:
	int posX;
	int posY;
	char button[3];
	char prevButton[3];
	int rot = 0;

public:

	void Update();
	void ButtonUpdate();

	/// <summary>
	/// マウスポインターの値をセットする
	/// </summary>
	/// <param name="x">x座標</param>
	/// <param name="y">y座標</param>
	void SetMousePoint(int x, int y);

	/// <summary>
	/// マウスのボタンが押されているかを返す
	/// </summary>
	/// <param name="buttonnum">ボタンの種類</param>
	/// <returns>押されているか</returns>
	bool IsPush(int buttonnum);

	/// <summary>
	/// マウスのボタンが押された瞬間であるかを返す
	/// </summary>
	/// <param name="buttonnum">ボタンの種類</param>
	/// <returns>押された瞬間であるか</returns>
	bool IsTrigger(int buttonnum);

	/// <summary>
	/// ホイールの回転量をリセットする
	/// </summary>
	void ResetRot();

	/// <summary>
	/// マウスのx座標を取得する
	/// </summary>
	/// <returns>マウスのx座標</returns>
	int GetPosX();

	/// <summary>
	/// マウスのy座標を取得する
	/// </summary>
	/// <returns>マウスのy座標</returns>
	int GetPosY();

	/// <summary>
	/// マウスのホイール回転量を取得する
	/// </summary>
	/// <returns>マウスのホイール回転量</returns>
	int GetRot();

	/// <summary>
	/// マウスの回転向きを返す
	/// </summary>
	/// <returns>0...無回転 1...前回転 2...後回転</returns>
	int isWheelMoving();
};

