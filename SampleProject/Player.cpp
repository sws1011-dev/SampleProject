#include "Player.h"
#include <iostream>

#include "Item.h"

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


Player::Player(const string& name, const string& characterClass, bool isHardcore,
               int str, int dex, int vit, int eng)
    : Character(str, dex, vit, eng, 1), exp(0), expToNextLevel(100)
{
}

Player::~Player()
{
    cout << "[플레이어 소멸]" << name << "\n";
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

void Player::Loot(unique_ptr<Item> item)
{
    cout << "[획득]" << item->name << "\n";
    inventory.push_back(*item);
}
void Player::PrintInventory() const{
    // 인벤토리 출력
    cout << "=====================================================\n";
    cout << "\t\tINVENTORY\n";
    cout << "=====================================================\n";
    for (int j = 0; j < inventory.size(); j++)
    {
        string typeStr;
        if (inventory[j].type == ItemType::Weapon) typeStr = "Weapon";
        else if (inventory[j].type == ItemType::Armor) typeStr = "Armor";
        else typeStr = "Consumable";
        cout << j + 1 << ". " << inventory[j].name << "\n";
    }
    cout << "=====================================================\n";
    system("pause");
    system("cls");
}
