#include <iostream>
#include <vector>
#include <list>

#include "SceneManager.h"

using namespace std;

int main()
{
	SceneManager* sceneMan = SceneManager::GetInstance();

	int input = -1;

	printf("0 = Title,1 = NewGame,2 = GamePlay,3 = GameClear\n");
	while (input > 3 || input < 0)
	{
		scanf_s("%d", &input);

		if (input > 3 || input < 0)
		{
			printf("0`3‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
		}
	}

	sceneMan->ChangeScene(input);

	sceneMan->Draw();

	return 0;
}