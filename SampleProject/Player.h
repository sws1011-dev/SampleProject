#pragma once
#include <string>
#include <vector>
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
    vector<int> inventory;

public:
    Player(const string& name, const string& characterClass, bool isHardCore); // 외부입력 값 세팅 초기화

    // Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return charactorClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetExp() const { return exp; }
    int GetExpToNextLevel() const { return expToNextLevel; }

    // 기능(함수)
    int CriticalAttack() const;
    void LevelUp();
    void GainExp(int amount);
    void PreviewCritical() const;
    void PrintLevel() const;
    void Loot(int count = 3); // 빈 슬롯부터 count개의 아이템 획득 -> 인벤토리에 저장 + 출력
};
