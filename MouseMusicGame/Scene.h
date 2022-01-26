#pragma once
#include <string>

class Scene
{
	using string = std::string;
private:
	string scene;

public:

	Scene();

	/// <summary>
	/// �V�[�����Z�b�g����
	/// </summary>
	/// <param name="sceneName">�V�[����</param>
	void SetScene(string sceneName);

	/// <summary>
	/// ���݂̃V�[�������擾����
	/// </summary>
	/// <returns></returns>
	string GetNowScene();

	/// <summary>
	/// �V�[���������������`�F�b�N����
	/// </summary>
	/// <param name="sceneName">�V�[����</param>
	/// <returns></returns>
	bool CheckSceneName(string sceneName);
};

