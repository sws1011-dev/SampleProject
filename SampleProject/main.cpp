#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

	char userName[50];
	string charactorClass;
	int classChoiceInput;

	// 스탯 시스템 초기 설정
	int strength = 50, dexterity = 50, vitality = 50, energy = 50;
	int level = 1;
	int hp = vitality * 2;
	int mp = energy * 1.5;
	float attackDamage = strength * 0.2f;
	float attackSpeed = dexterity / 10.0f;
	double movingSpeed = dexterity / 30.0;
	int fireResist = 0, lightningResist = 0, coldResist = 0, poisonResist = 0;

	bool isHardcore = false;
	char hardcoreInput;	

	cout << "hp변수의 값 : " << hp << "\n";
	cout << "hp변수의 주소값 : " << &hp << "\n";

	int* ptr = &hp;
	cout << "ptr == &hp : " << ptr << "\n";
	cout << "ptr 값 : " << *ptr << "\n";

	*ptr = 200;
	cout << "hp변수의 새로운 값 : " << hp << "\n";
	cout << "ptr 역참조 값 : " << *ptr << "\n";


	system("pause");

	// [UI] 타이틀 화면 (아스키 아트 추가)
	cout << "=====================================================\n";
	cout << "       DIABLO STYLE CONSOLE ADVENTURE v1.0         \n";
	cout << "=====================================================\n";
	cout << "                _,--.      ,--._                \n";
	cout << "              /  _   \\    /   _  \\              \n";
	cout << "             |  (O)   |  |   (O)  |             \n";
	cout << "              \\      /    \\      /              \n";
	cout << "               `--'        `--'                 \n";
	cout << "                   _      _                     \n";
	cout << "            \\    / \\____/ \\    /              \n";
	cout << "             \\__/          \\__/               \n";
	cout << "                \\__________/                    \n";
	cout << "=====================================================\n\n";

	cout << " >> Input your Hero's name : ";
	cin >> userName;

	cout << "\n-----------------------------------------------------\n";
	cout << " [ SELECT YOUR CLASS ] \n";
	cout << " 1. Amazon      2. Assassin    3. Barbarian    4. Druid\n";
	cout << " 5. Necromancer 6. Paladin     7. Sorceress    8. Warlock\n";
	cout << "-----------------------------------------------------\n";
	cout << " >> Choice : ";
	cin >> classChoiceInput;

	switch (classChoiceInput) {
	case 1: charactorClass = "Amazon"; break;
	case 2: charactorClass = "Assassin"; break;
	case 3: charactorClass = "Barbarian"; break;
	case 4: charactorClass = "Druid"; break;
	case 5: charactorClass = "Necromancer"; break;
	case 6: charactorClass = "Paladin"; break;
	case 7: charactorClass = "Sorceress"; break;
	case 8: charactorClass = "Warlock"; break;
	default: charactorClass = "Unknown"; break;
	}

	cout << "\n >> Enable Hardcore Mode? (1: Yes / 2: No) : ";
	cin >> hardcoreInput;
	isHardcore = (hardcoreInput == '1');

	system("cls"); // 화면 전환

	// [UI] 캐릭터 정보창 (HP/MP 게이지 추가)
	int maxHp = vitality * 2;
	int maxMp = (int)(energy * 1.5);

	cout << "\n\n";
	cout << "        [ CHARACTER PROFILE ]\n";
	cout << "=====================================================\n";
	cout << " Name   : " << userName << "\t\tClass : " << charactorClass << "\n";
	cout << " Level  : " << level << "\t\tMode  : " << (isHardcore ? "HARDCORE" : "STANDARD") << "\n";
	cout << "-----------------------------------------------------\n";
	cout << " [STATS]                 [RESISTANCES]\n";
	
	int hpBars = (hp * 10) / maxHp;
	cout << " HP : [";
	for (int i = 0; i < 10; i++) cout << (i < hpBars ? "#" : " ");
	cout << "] " << hp << "/" << maxHp << "\t Fire      : " << fireResist << "%\n";

	int mpBars = (mp * 10) / maxMp;
	cout << " MP : [";
	for (int i = 0; i < 10; i++) cout << (i < mpBars ? "*" : " ");
	cout << "] " << mp << "/" << maxMp << "\t Lightning : " << lightningResist << "%\n";

	cout << " STR: " << strength << " \t\t Cold      : " << coldResist << "%\n";
	cout << " DEX: " << dexterity << " \t\t Poison    : " << poisonResist << "%\n";
	cout << "-----------------------------------------------------\n";
	cout << " ATK DMG : " << attackDamage << " | ATK SPD : " << attackSpeed << " | MOV SPD : " << movingSpeed << "\n";
	cout << "=====================================================\n\n";

	system("pause");
	system("cls"); // 전투 전 화면 전환

	// 전투 시스템
	int maxGoblinHp = 30;
	int goblinHp = maxGoblinHp;
	int action;

	while (goblinHp > 0 && hp > 0) {
		cout << "\n";
		cout << "      (o)(o)  \n";
		cout << "   /----------\\ \n";
		cout << "  /  |      |  \\  <-- GOBLIN \n";
		cout << "     |  @@  |    \n";
		cout << "     \\______/    \n";
		cout << "!!! WARNING: A WILD GOBLIN APPEARED !!!\n";

		// 동일한 비율의 게이지 표시 (각자의 MaxHP 대비)
		int pBars = (hp * 10) / maxHp;
		int gBars = (goblinHp * 10) / maxGoblinHp;

		cout << "\n+-----------------------------------------------------------+\n";
		cout << "  GOBLIN HP: [";
		for (int i = 0; i < 10; i++) cout << (i < gBars ? "#" : " ");
		cout << "] " << (goblinHp > 0 ? goblinHp : 0) << "  |  YOUR HP: [";
		for (int i = 0; i < 10; i++) cout << (i < pBars ? "#" : " ");
		cout << "] " << (hp > 0 ? hp : 0) << "\n";
		cout << "+-----------------------------------------------------------+\n";
		cout << " [1] Physical Attack    [2] Run Away\n";
		cout << " >> Action : ";
		cin >> action;

		system("cls"); // 매 턴 행동 후 화면 전환

		if (action == 1) {
			cout << "\n>> [YOU] attacked the Goblin for " << (int)attackDamage << " damage!\n";
			goblinHp -= (int)attackDamage;

			if (goblinHp > 0) {
				cout << ">> [GOBLIN] counter-attacked! You lost 30 HP.\n";
				hp -= 30;
			}
		}
		else {
			cout << ">> [SYSTEM] You failed to act! The Goblin strikes! (-30 HP)\n";
			hp -= 30;
		}
	}

	// 마지막 전투 메시지 확인 후 결과창으로 전환
	cout << "\n>> Battle ended. Press any key to see the result...\n";
	system("pause");
	system("cls");

	// 결과 판정
	cout << "\n=====================================================\n";
	if (hp <= 0) {
		cout << "             [ !!! YOU ARE DEAD !!! ]                \n";
		if (isHardcore) cout << "        Your journey ends here forever...            \n";
	}
	else {
		cout << "             [ VICTORY IN SANCTUARY ]                \n";
		cout << "-----------------------------------------------------\n";

		srand((unsigned int)time(NULL));
		cout << " [LOOT FOUND]\n";
		for (int i = 1; i <= 3; i++) {
			int lootRoll = rand() % 4;
			string itemName = (lootRoll == 0) ? "Gold" : (lootRoll == 1) ? "Healing Potion" : (lootRoll == 2) ? "Weapon" : "Armor";
			cout << "  - (" << i << ") " << itemName << "\n";
		}
	}
	cout << "=====================================================\n";

	return 0;
}