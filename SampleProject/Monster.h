#pragma once
using namespace std;

class Monster
{
private:
    int hp, maxHp;
    int attackDamage;

public:
    Monster(int initHp, int atk);
    ~Monster();

    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    bool IsAlive() const { return hp > 0; }
    void TakeDamage(int damage); // 몬스터가 피해를 받음
    int Attack() const { return attackDamage; } // 몬스터가 플레이어를 공격
};
