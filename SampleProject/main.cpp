#include <iostream>

using namespace std;

int main()
{
	char userName[50];
	char charactorClass[50];

	// 1. 다양한 자료형의 변수 선언 및 초기값 할당

	// 스탯 시스템
	int strength = 50;
	int dexterity = 50;
	int vitality = 50;
	int energy = 50;

	int level = 1;
	int hp = vitality * 2;
	int mp = energy * 1.5;
	float attackDamage = strength * 0.2f;
	float attackSpeed = dexterity / 10.0f;
	double movingSpeed = dexterity / 30.0;
	int fireResist = 0;
	int lightningResist = 0;
	int coldResist = 0;
	int poisonResist = 0;

	// 하드코어 모드 여부 변수
	bool isHardcore = true;

	cout << "[Character Creation]\n";
	cout << "Input your name : ";
	cin >> userName;
	cout << "Input your Class : ";
	cin >> charactorClass;
	cout << "\n::::::::::::::::::: Welcome to the Sanctuary :::::::::::::::::\n";
	cout << "User Name : [" << userName << "]\n";

	// 2. 변수에 저장된 데이터 출력
	cout << "--------------------------Character Status--------------------------\n";
	cout << "Class : " << charactorClass << "\n";
	cout << "Level : " << level << "\n";
	cout << "HP : " << hp << "\n";
	cout << "MP : " << mp << "\n";
	cout << "Attack Damage: " << attackDamage << "\n";
	cout << "Attack Speed : " << attackSpeed << "\n";
	cout << "Moving Speed : " << movingSpeed << "\n";
	cout << "Strength : " << strength << "\n";
	cout << "Dexterity : " << dexterity << "\n";
	cout << "Vitality : " << vitality << "\n";
	cout << "Energy : " << energy << "\n\n";

	cout << "Hardcore Mode : " << isHardcore << " (1: true, 0: false)\n\n";

	cout << "Fire Resistance : " << fireResist << "\n";
	cout << "Lightning Resistance : " << lightningResist << "\n";
	cout << "Cold Resistance : " << coldResist << "\n";
	cout << "Poision Resistance : " << poisonResist << "\n";

	cout << "-----------------------------------------------------\n";

	// 3. sizeof 연산자를 이용한 메모리 크기 확인
	cout << "[Memory Check] int type size : " << sizeof(hp) << "bytes\n";
	cout << "[Memory Check] bool type size : " << sizeof(isHardcore) << "bytes\n";
	cout << "[Memory Check] float type size : " << sizeof(float) << "bytes\n";
	cout << "[Memory Check] float type size : " << sizeof(double) << "bytes\n";
	cout << "[Memory Check] char type size : " << sizeof(char) << "bytes\n";
	cout << "[Memory Check] char array(userName) size : " << sizeof(userName) << "bytes\n";

	return 0;
}