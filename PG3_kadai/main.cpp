#include <iostream>
#include <vector>
#include <list>

#include "SceneManager.h"

using namespace std;

int main()
{
	SceneManager* sceneMan = SceneManager::GetInstance();

	int input = -1;
	printf("1 = Title,2 = NewGame,3 = GamePlay,4 = GameClear\n");

	while (input != 0)
	{
		input = -1;
		while (input > 4 || input < 1)
		{
			scanf_s("%d", &input);

			if (input > 4 || input < 1)
			{
				printf("1`4‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B\n");
			}
		}

		sceneMan->ChangeScene(input);

		sceneMan->Draw();
	}

	return 0;
}