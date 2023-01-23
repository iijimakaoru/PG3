#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	// 山手線
	list<const char*> stationName
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
	for (auto itr = stationName.begin(); itr != stationName.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2019
	printf("2019年\n");
	list<const char*>::iterator name1970 = next(stationName.begin(), 7);
	stationName.insert(name1970, "Nishi-Nippori");
	for (auto itr = stationName.begin(); itr != stationName.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2022
	printf("2022年\n");
	list<const char*>::iterator name2019 = next(stationName.begin(), 25);
	stationName.insert(name2019, "TakanawaGateWay");
	for (auto itr = stationName.begin(); itr != stationName.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	return 0;
}