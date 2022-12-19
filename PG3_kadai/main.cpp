#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <functional>
#include <list>
#include <string>

using namespace std;

int main()
{
	list<const char*> name{ "oosaki","gotanda","meguro","ebisu","sibuya","harazyuku","yoyogi","sinzyuku","sinookubo","takadanobaba","meziro","ikebukuro","ootuka", "sugamo",
	"komagome","tabata","nippori","uguisudani","ueno","okatimati","akihabara","kanda","toukyou","yuurakutyou","sinbasi","hamamatutyou","tamati","sinagawa"};

	for (int i = 0; i < name.size(); i++)
	{
		printf("%s\n", name);
	}

	return 0;
}