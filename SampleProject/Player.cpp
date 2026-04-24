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
    for (int i = 0; i < 5; i++) inventory[i] = 0;
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
