#include <iostream>
#include <vector>
#include <list>

using namespace std;

void PrintStationName(list<const char*>& list)
{
	for (auto itr = list.begin(); itr != list.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");
}

int main()
{
	// 山手線
	list<const char*> stationNames
	{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanohara",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatutsucho",
		"Shimbasi",
		"Yurakucho"
	};

	// 1970
	printf("1970年\n");
	PrintStationName(stationNames);

	// 2019
	printf("2019年\n");
	list<const char*>::iterator stationNames1970 = next(stationNames.begin(), 7);
	stationNames.insert(stationNames1970, "Nishi-Nippori");
	PrintStationName(stationNames);

	// 2022
	printf("2022年\n");
	list<const char*>::iterator stationNames2019 = next(stationNames.begin(), 25);
	stationNames.insert(stationNames2019, "TakanawaGateWay");
	PrintStationName(stationNames);

	return 0;
}