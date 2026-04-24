#include "Monster.h"
#include <iostream>


Monster::Monster(int initHp, int atk):hp(initHp), maxHp(initHp), attackDamage(atk)
{
    cout << "[몬스터 등장!] HP: " << hp << " / ATK: " << attackDamage << "\n";
}

Monster::~Monster()
{
    cout << "[몬스터 소멸!]\n"; // 소멸자 확인용 로그
}

void Monster::TakeDamage(int damage)
{
    hp -= damage;
    if (hp < 0) hp = 0; // 음수 방지
}