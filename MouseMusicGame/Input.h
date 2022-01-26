#pragma once

class Input
{
private:
	char Keys[256];
	char PrevKeys[256];

public:
	void Update();

	/// <summary>
	/// キーが押されているかを返す
	/// </summary>
	/// <param name="keynum">キーの種類</param>
	/// <returns>押されているか</returns>
	bool IsPush(int keynum);

	/// <summary>
	/// キーが押された瞬間であるかを返す
	/// </summary>
	/// <param name="keynum">キーの種類</param>
	/// <returns>押された瞬間であるか</returns>
	bool IsTrigger(int keynum);
};