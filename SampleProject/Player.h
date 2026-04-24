#pragma once
#include <string>

using namespace std;

// Player 클래스
class Player
{
private:
    // 기본 정보
    string name;
    string charactorClass;
    bool isHardcore;

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

    // 인벤토리
    int inventory[5];

public:
    Player(const string& name, const string& characterClass, bool isHardCore); // 외부입력 값 세팅 초기화


    // Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return charactorClass; }
    bool IsHardcore() const { return isHardcore; }
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

    int* GetInventory() { return inventory; }

    // 기능(함수)
    bool IsAlive() const { return hp > 0; }
    void TakeDamage(int damage);
    int Attack() const;
    int CriticalAttack() const;
    void LevelUp();
    void PreviewCritical() const;
    void PrintLevel() const;
};
