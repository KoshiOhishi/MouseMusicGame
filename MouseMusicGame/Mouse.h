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
	/// �}�E�X�|�C���^�[�̒l���Z�b�g����
	/// </summary>
	/// <param name="x">x���W</param>
	/// <param name="y">y���W</param>
	void SetMousePoint(int x, int y);

	/// <summary>
	/// �}�E�X�̃{�^����������Ă��邩��Ԃ�
	/// </summary>
	/// <param name="buttonnum">�{�^���̎��</param>
	/// <returns>������Ă��邩</returns>
	bool IsPush(int buttonnum);

	/// <summary>
	/// �}�E�X�̃{�^���������ꂽ�u�Ԃł��邩��Ԃ�
	/// </summary>
	/// <param name="buttonnum">�{�^���̎��</param>
	/// <returns>�����ꂽ�u�Ԃł��邩</returns>
	bool IsTrigger(int buttonnum);

	/// <summary>
	/// �z�C�[���̉�]�ʂ����Z�b�g����
	/// </summary>
	void ResetRot();

	/// <summary>
	/// �}�E�X��x���W���擾����
	/// </summary>
	/// <returns>�}�E�X��x���W</returns>
	int GetPosX();

	/// <summary>
	/// �}�E�X��y���W���擾����
	/// </summary>
	/// <returns>�}�E�X��y���W</returns>
	int GetPosY();

	/// <summary>
	/// �}�E�X�̃z�C�[����]�ʂ��擾����
	/// </summary>
	/// <returns>�}�E�X�̃z�C�[����]��</returns>
	int GetRot();

	/// <summary>
	/// �}�E�X�̉�]������Ԃ�
	/// </summary>
	/// <returns>0...����] 1...�O��] 2...���]</returns>
	int isWheelMoving();
};

