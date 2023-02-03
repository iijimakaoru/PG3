#include <iostream>
#include <vector>
#include <list>

#include "SceneManager.h"

using namespace std;

int main()
{
	SceneManager* sceneMan = SceneManager::GetInstance();

	while (true)
	{
		if (sceneMan->GetScene() + 1 > sceneMan->maxScene)
		{
			sceneMan->ChangeScene(0);
		}
		else
		{
			sceneMan->ChangeScene(sceneMan->GetScene() + 1);
		}

		sceneMan->Draw();
	}

	return 0;
}