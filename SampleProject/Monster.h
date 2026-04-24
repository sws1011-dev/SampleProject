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

    int GetExpReward() const {return expReward; };
    string GetName() const {return name; };
};
