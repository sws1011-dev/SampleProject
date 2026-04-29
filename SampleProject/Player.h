#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Character.h"
#include "Item.h"

using namespace std;

class Mercenary; // 전방선언

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
    vector<Item> inventory;
    
protected:
    // 자식 클래스(바바리안, 소서리스 등)이 스탯을 직접 지정할때 사용되는 생성자
    Player(const string& name, const string& characterClass, bool isHardcore,
        int str, int dex, int vit, int eng);
	
public:
    Player(const string& name, const string& characterClass, bool isHardCore); // 외부입력 값 세팅 초기화
    virtual ~Player();

    // Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return charactorClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetExp() const { return exp; }
    int GetExpToNextLevel() const { return expToNextLevel; }

    // 플레이어 -> 용병 참조
    shared_ptr<Mercenary> companion;
    
    // 기능(함수)
    int CriticalAttack() const;
    virtual string GetAttackMessage() const { return ""; }
    void LevelUp();
    void GainExp(int amount);
    void PreviewCritical() const;
    void PrintLevel() const;
    void Loot(unique_ptr<Item> item);   // 소유권 이전을 통한 아이템 획득
    void PrintInventory() const;    // 인벤토리 전체 출력
};
