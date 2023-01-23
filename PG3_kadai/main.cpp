#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	// �R���
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
	printf("1970�N\n");
	for (auto itr = stationNames.begin(); itr != stationNames.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2019
	printf("2019�N\n");
	list<const char*>::iterator stationNames1970 = next(stationNames.begin(), 7);
	stationNames.insert(stationNames1970, "Nishi-Nippori");
	for (auto itr = stationNames.begin(); itr != stationNames.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2022
	printf("2022�N\n");
	list<const char*>::iterator stationNames2019 = next(stationNames.begin(), 25);
	stationNames.insert(stationNames2019, "TakanawaGateWay");
	for (auto itr = stationNames.begin(); itr != stationNames.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	return 0;
}