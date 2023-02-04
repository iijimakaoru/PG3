#include <iostream>
#include <vector>
#include <list>
#include <string>

#include "Enemy.h"

using namespace std;

int main()
{
	Enemy enemy1 = Enemy(1);
	Enemy enemy2 = Enemy(2);
	Enemy enemy3 = Enemy(3);

	while (true)
	{
		enemy1.Update();
		enemy2.Update();
		enemy3.Update();

		int input = -1;

		if (!enemy1.GetIsAlive(), !enemy2.GetIsAlive(), !enemy3.GetIsAlive())
		{
			printf("‚ ‚È‚½‚ÍŸ—˜‚µ‚½I\n");
			break;
		}

		printf("‚Ç‚ê‚ğUŒ‚‚·‚éH\n");

		scanf_s("%d", &input);
		
		switch (input)
		{
		case 1:
			if (enemy1.GetIsAlive())
			{
				printf("“G%d‚ÖUŒ‚I\n", input);

				printf("“G%d‚Í”š”­‚µ‚½I\n", input);

				enemy1.Death();
			}
			else
			{
				enemy1.CorpseKick();
			}
			break;
		case 2:
			if (enemy2.GetIsAlive())
			{
				printf("“G%d‚ÖUŒ‚I\n", input);

				printf("“G%d‚Í”š”­‚µ‚½I\n", input);

				enemy2.Death();
			}
			else
			{
				enemy2.CorpseKick();
			}
			break;
		case 3:
			if (enemy3.GetIsAlive())
			{
				printf("“G%d‚ÖUŒ‚I\n", input);

				printf("“G%d‚Í”š”­‚µ‚½I\n", input);

				enemy3.Death();
			}
			else
			{
				enemy3.CorpseKick();
			}
			break;
		default:
			break;
		}
	}

	return 0;
}