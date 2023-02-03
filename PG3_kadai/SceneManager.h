#pragma once
#include <stdio.h>

class SceneManager final
{
public:
	static SceneManager* GetInstance();
	void ChangeScene(int sceneNo);
	void Draw();
	int GetScene() { return scene; }

	static const int maxScene = 3;

private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager& s) = delete;
	SceneManager& operator = (const SceneManager& s) = delete;

private:
	int scene = 0;
};

