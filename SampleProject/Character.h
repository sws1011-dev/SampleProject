#pragma once
#include <algorithm>
#include <iostream>

using namespace std;

class Character
{
protected:
    // 기본 능력치
    int strength, dexterity, vitality, energy;

    //파생 능력치
    int level;
    int hp, maxHp, mp, maxMp;
    float attackDamage;
    float attackSpeed;
    double movingSpeed;

    // 저항 능력치
    int fireResist, lightningResist, coldResist, poisonResist;

public:
    // Constructor
    Character(int str, int dex, int vit, int eng, int lv = 1);
    virtual ~Character() {}   // 가상 소멸자: 자식 소멸자까지 안전하게 호출
    
    // Getters
    int GetStrength() const { return strength; }
    int GetDexterity() const { return dexterity; }
    int GetVitality() const { return vitality; }
    int GetEnergy() const { return energy; }
    int GetLevel() const { return level; }
    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    int GetMp() const { return mp; }
    int GetMaxMp() const { return maxMp; }
    float GetAttackDamage() const { return attackDamage; }
    float GetAttackSpeed() const { return attackSpeed; }
    double GetMovingSpeed() const { return movingSpeed; }
    int GetFireResist() const { return fireResist; }
    int GetLightningResist() const { return lightningResist; }
    int GetColdResist() const { return coldResist; }
    int GetPoisonResist() const { return poisonResist; }
    bool IsAlive() const { return hp > 0; }
    void TakeDamage(int damage);
    virtual int Attack() const;
    void Heal(int amount) { hp = min(amount+hp, maxHp); } // HP(힐량만큼) 회복, maxHP 초과 불가
};
