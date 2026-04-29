#pragma once
#include <memory>
#include <string>
#include <iostream>
#include <ostream>

#include "Player.h"

using namespace std;

class Mercenary
{
public:
    string name;
    int attackDamage;
    shared_ptr<Player> owner;

    Mercenary(const string name, int atk, shared_ptr<Player> owner);
    ~Mercenary();

    int Attack() const { return attackDamage; }
    bool IsOwnerAlive() const { return owner != nullptr; }  // 주인이 살아있는지 확인
};
