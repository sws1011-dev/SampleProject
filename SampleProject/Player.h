#pragma once
#include <string>
#include "Character.h"

using namespace std;

// Character 클래스를 상속 받은 Player 클래스
class Player : public Character
{
private:
    // Player 고유 정보
    string name;
    string charactorClass;
    bool isHardcore;
    
    // 경험치
    int exp, expToNextLevel;
    
    // 인벤토리
    int inventory[5];

public:
    Player(const string& name, const string& characterClass, bool isHardCore); // 외부입력 값 세팅 초기화

    // Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return charactorClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetExp() const { return exp; }
    int GetExpToNextLevel() const { return expToNextLevel; }
    int* GetInventory() { return inventory; }

    // 기능(함수)
    int CriticalAttack() const;
    void LevelUp();
    void GainExp(int amount);
    void PreviewCritical() const;
    void PrintLevel() const;
};
