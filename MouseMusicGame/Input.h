#pragma once

class Input
{
private:
	char Keys[256];
	char PrevKeys[256];

public:
	void Update();

	/// <summary>
	/// �L�[��������Ă��邩��Ԃ�
	/// </summary>
	/// <param name="keynum">�L�[�̎��</param>
	/// <returns>������Ă��邩</returns>
	bool IsPush(int keynum);

	/// <summary>
	/// �L�[�������ꂽ�u�Ԃł��邩��Ԃ�
	/// </summary>
	/// <param name="keynum">�L�[�̎��</param>
	/// <returns>�����ꂽ�u�Ԃł��邩</returns>
	bool IsTrigger(int keynum);
};