#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	// �R���
	list<const char*> name
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
	for (auto itr = name.begin(); itr != name.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2019
	printf("2019�N\n");
	list<const char*>::iterator name1970 = next(name.begin(), 7);
	name.insert(name1970, "Nishi-Nippori");
	for (auto itr = name.begin(); itr != name.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	// 2022
	printf("2022�N\n");
	list<const char*>::iterator name2019 = next(name.begin(), 25);
	name.insert(name2019, "TakanawaGateWay");
	for (auto itr = name.begin(); itr != name.end(); ++itr)
	{
		cout << *itr << "\n";
	}
	printf("\n");

	return 0;
}