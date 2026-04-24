#include "Player.h"
#include <iostream>

Player::Player(const string& name, const string& characterClass, bool isHardCore)
// 외부입력 값 세팅 초기화
    : Character(50, 50, 50, 50, 1),
      name(name), charactorClass(characterClass), isHardcore(isHardCore), // 단순 값 세팅 초기화
      exp(0), expToNextLevel(100)
{
    maxHp = vitality * 2; // 계산이 필요한 값 세팅
    hp = maxHp;
    maxMp = (int)(energy * 1.5);
    mp = maxMp;
    attackDamage = strength * 0.2f;
    attackSpeed = dexterity / 10.0f;
    movingSpeed = dexterity / 30.0f;
}

int Player::CriticalAttack() const { return (int)(attackDamage * 2); }

void Player::LevelUp() { level++; }

void Player::PreviewCritical() const
{
    float preview = attackDamage * 2;
    cout << "크리티컬 예상 데미지: " << preview << "\n";
}

void Player::PrintLevel() const
{
    cout << "현재 레벨: " << level << "\n";
}

void Player::GainExp(int amount)
{
    exp += amount;
    if (exp >= expToNextLevel)
    {
        exp -= expToNextLevel;
        level++;
        expToNextLevel = level * 100;
        cout << "[레벨 업!] Level: " << level << "\n";
    }
}

void Player::Loot(int count)
{
    cout << " [LOOT FOUND]\n";

    // count개의 아이템을 vector에 추가
    for (int i = 0; i < count; i++)
    {
        // 랜덤 숫자 1개씩 인벤토리에 벡터에 넣음
        inventory.push_back(rand() % 4 + 1);
    }
    // 인벤토리 출력
    cout << "=====================================================\n";
    cout << "\t\tINVENTORY\n";
    cout << "=====================================================\n";
    for (int j = 0; j < inventory.size(); j++)
    {
        string itemName;
        if (inventory[j] == 1) itemName = "Gold";
        else if (inventory[j] == 2) itemName = "Healing Potion";
        else if (inventory[j] == 3) itemName = "Weapon";
        else if (inventory[j] == 4) itemName = "Armor";
        else itemName = "None";
        cout << j + 1 << ". " << itemName << "\n";
    }
    cout << "=====================================================\n";
    system("pause");
    system("cls");
}
