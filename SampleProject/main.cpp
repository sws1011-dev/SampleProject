#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Call By Value: 복사본 전달 -> 원본은 변경 불가
void PreviewCritical(float attackDamage) {
	attackDamage *= 2;	// Parameter 복사본만 2배, 원본 변수는 그대로
	cout << "크리티컬 예상 데미지:" << attackDamage << "\n";
}

// Call By Address: 주소 전달 -> 원본 직접 수정 가능
void LevelUp(int* level) {
	(*level)++;	// 역참조로 level 원본 직접 증가
}

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

	// 인벤토리 (0=빈칸, 1=Gold, 2=Healing Potion, 3=Weapon, 4=Armor)
	int gameInventory[5] = { 0 };

	// Call By Value : 복사본 전달 -> 원본의 불변 확인
	cout << "원본 attackDamage: " << attackDamage << "\n";
	PreviewCritical(attackDamage);
	cout << "호출 이후 attackDamage: " << attackDamage << "\n";

	// Call By Address: 주소값 전달 -> 원본 직접 수정
	cout << "레벨업 전 level: " << level << "\n";
	LevelUp(&level);
	cout << "레벨업 후 level: " << level << "\n";

	// Call By Reference: 별칭(Alias) 선언 -> 원본과 같은 메모리
	int& levelRef = level;	// level의 별칭 선언
	levelRef++;	// levelRef 수정 -> level이 수정될 것임
	cout << "levelRef++ 후 원본 level: " << level << "\n";
	cout << "levelRef++과 level이 동일한 값?: " << levelRef << "\n";


	/**
	* 문서화를 위한 주석
	*/

	/*	cout << "hp변수의 값 : " << hp << "\n";
		cout << "hp변수의 주소값 : " << &hp << "\n";

		int* ptr = &hp;
		cout << "ptr == &hp : " << ptr << "\n";
		cout << "ptr 값 : " << *ptr << "\n";

		*ptr = 200;
		cout << "hp변수의 새로운 값 : " << hp << "\n";
		cout << "ptr 역참조 값 : " << *ptr << "\n";

		//int* ptr2 = nullptr;
		//cout << "nullptr 할당한 주소 : " << ptr2 << "\n";
		//cout << "nullptr 할당한 값 : " << *ptr2 << "\n";

		cout << "sizeof(int) : " << sizeof(int) << "bytes\n";
		cout << "sizeof(int*) : " << sizeof(int*) << "bytes\n";
		cout << "sizeof(double*) : " << sizeof(double*) << "bytes\n";
		cout << "sizeof(char*) : " << sizeof(char*) << "bytes\n";

		// 포인터 연산 (+1 = 자료형 메모리 크기만큼 이동)
		cout << "ptr : " << ptr << "\n";
		cout << "ptr+1 : " << ptr + 1 << "\n";
		cout << "ptr+2 : " << ptr + 2 << "\n";

		// 배열의 메모리 구조 확인
		int scores[5] = { 85, 92, 78, 95, 88 };
		cout << "&scores[0] : " << &scores[0] << "\n";
		cout << "&scores[1] : " << &scores[1] << "\n";
		cout << "&scores[2] : " << &scores[2] << "\n";
		cout << "&scores[3] : " << &scores[3] << "\n";
		cout << "&scores[4] : " << &scores[4] << "\n";

		// 배열 이름이 시작 주소로 형변환(Pointer Decay)
		cout << "scores : " << scores << "\n";			// 배열 이름
		cout << "&scores[0] : " << &scores[0] << "\n";	// 첫 원소 주소
		cout << "scores[2] : " << &scores[2] << "\n";	// 인덱스로 접근
		cout << "(scores+2) : " << (scores + 2) << "\n";	// 포인터 연산
		cout << "*(scores+2) : " << *(scores + 2) << "\n";	// 포인터 연산

		// 형변환의 예외상황 1. sizeof() 사용
		cout << "sizeof(scores) : " << sizeof(scores) << "\n";
		cout << "sizeof(scores[0]) : " << sizeof(scores[0]) << "\n";
		cout << "scores의 원소개수 : " << sizeof(scores) / sizeof(scores[0]) << "\n";

		// 형변환의 예외상황 2. &(주소) 연산자 사용
		cout << "scores : " << scores << "\n";			// 시작 주소
		cout << "scores + 1 : " << scores + 1 << "\n";	// +4
		cout << "&scores : " << &scores << "\n";		// 시작 주소
		cout << "&(scores + 1) : " << &scores + 1 << "\n";	// +20 배열 전체 단위로 이동

		// for 반복문을 통한 배열 순환
		int* sPtr = scores;

		for (int i = 0; i < sizeof(scores) / sizeof(scores[0]); i++) {
			cout << "주소 : " << sPtr << ", 값 : " << *sPtr << "\n";
			sPtr++;	// +1 다음 원소로 이동
		}

		// Wild Pointer 위험
		//int* wildPtr; // 초기화 안 함 -> 쓰레기 주소값이 들어갈 것임
		//*wildPtr = 100; // CRASH 발생. 잘못된 메모리에 접근하고 있음


		// 포인터 변수 선언 시 안전한 초기화 예시문
		int* wildPtr = nullptr;		// 안전한 초기화를 위한 예약어 nullptr 사용.
		if (wildPtr != nullptr) {	// wildPtr의 null 체크 조건문
			*wildPtr = 100;	// 실행안됨
		}

		cout << "wildPtr : " << wildPtr << "\n"; // 0

		// 허상 포인터 예시
		int* danglePtr = new int(100); // 동적 할당
		cout << "삭제(delete) 전 : " << *danglePtr << "\n"; // 100
		delete danglePtr;		// 메모리 해제, 삭제
		// *danglePtr = 200;	// 해제된 메모리에 할당하려 하고 있음. Runtime CRASH 발생
		danglePtr = nullptr;	// 안전처리
		cout << "삭제(delete) 후 : " << danglePtr << "\n"; // ??

		system("pause");*/

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

		int* invPtr = gameInventory;	// invPtr -> gameInventory 시작 주소 [0]

		// 포인터로 인벤토리에 랜덤 숫자 저장
		for (int i = 1; i <= 3; i++) {
			*invPtr = rand() % 4 + 1;	// 역참조로 현재 칸에 아이템 코드를 저장하고자 함
			invPtr++;
		}

		// 포인터 순회로 인벤토리 출력(5칸)
		invPtr = gameInventory;			// invPtr 처음 주소로 리셋
		int slot = 0;
		cout << "=====================================================\n";
		cout << "\t\tINVENTORY\n";
		cout << "=====================================================\n";
		while (invPtr < gameInventory + 5) {
			string itemName;
			if (*invPtr == 1) itemName = "Gold";
			else if (*invPtr == 2) itemName = "Healing Potion";
			else if (*invPtr == 3) itemName = "Weapon";
			else if (*invPtr == 4) itemName = "Armor";
			else itemName = "None";
			cout << slot++ << ". " << itemName << "\n";
			invPtr++;
		}
	}
	cout << "=====================================================\n";

	return 0;
}