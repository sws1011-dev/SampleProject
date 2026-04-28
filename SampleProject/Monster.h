#pragma once
#include <string>

#include "Character.h"
using namespace std;

class Monster : public Character
{
private:
    string name;
    int expReward;

public:
    Monster(const string name, int str, int dex, int vit, int eng, int expReward, int lv = 1);
    virtual ~Monster(); // 소멸자 타이밍 확인용

    int GetExpReward() const {return expReward; };
    string GetName() const {return name; };
    
    virtual string GetAttackMessage() const { return ""; }
};
