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
	/// シーンをセットする
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	void SetScene(string sceneName);

	/// <summary>
	/// 現在のシーン名を取得する
	/// </summary>
	/// <returns></returns>
	string GetNowScene();

	/// <summary>
	/// シーン名が正しいかチェックする
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	/// <returns></returns>
	bool CheckSceneName(string sceneName);
};

