#pragma once
#include "Character.h"
using namespace std;

class Monster : public Character
{
private:
    int expReward;

public:
    Monster(int str, int dex, int vit, int eng, int expReward, int lv = 1);

    int GetExpReward() const {return expReward; };
};
