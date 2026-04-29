#include "Player.h"
#include <iostream>

#include "Item.h"

Player::Player(const string& name, const string& characterClass, bool isHardCore)
// 외부입력 값 세팅 초기화
    : Character(50, 50, 50, 50, 1),
      name(name), charactorClass(characterClass), isHardcore(isHardCore), // 단순 값 세팅 초기화
      exp(0), expToNextLevel(100)
{
    inventory.reserve(6); // 재할당에 따른 복사 (Reallocation)를 방지하기 위해 미리 capacity 확보
}


Player::Player(const string& name, const string& characterClass, bool isHardcore,
               int str, int dex, int vit, int eng)
    : Character(str, dex, vit, eng, 1), exp(0), expToNextLevel(100)
{
    inventory.reserve(6);
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

void Player::Loot(Item item)
{
    cout << "[획득]" << item.name << "\n";
    inventory.emplace_back(move(item)); // Item을 인벤토리 안으로 직접 이동
    cout <<"[인벤토리] size = " << inventory.size() << ", capacity = " << inventory.capacity() << "\n";
}
void Player::PrintInventory() const{
    // 인벤토리 출력
    cout << "=====================================================\n";
    cout << "\t\tINVENTORY\n";
    cout << "=====================================================\n";
    
    int i = 1;
    // Range-based for문 + const auto&
    for (const auto& item : inventory)
    {
        string typeStr;
        if (item.type == ItemType::Weapon) typeStr = "Weapon";
        else if (item.type == ItemType::Armor) typeStr = "Armor";
        else typeStr = "Consumable";
        cout << i++ << ". " << item.name << "\n";
    }
    cout << "=====================================================\n";
    system("pause");
    system("cls");
}
