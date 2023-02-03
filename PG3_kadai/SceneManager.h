#pragma once
#include <stdio.h>

class SceneManager
{
public:
	static SceneManager* GetInstance();
	void ChangeScene(int sceneNo);
	void Draw();
	int GetScene() { return scene; }

private:
	int scene = 0;
};

