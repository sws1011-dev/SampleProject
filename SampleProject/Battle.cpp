#include <iostream>
#include "Battle.h"

#include "Mercenary.h"

using namespace std;

Battle::Battle(Player& player, Monster& monster, shared_ptr<Mercenary> mercenary)
    : player(player), monster(monster), mercenary(mercenary), combatMessage("[System] Battle Started!")
{
}

bool Battle::Run()
{
    int action;
    
    // lock() : weak_ptr에서 임시로 shared_ptr을 통해 데이터 접근
    if (mercenary)
    {
        auto ownerPtr = mercenary->owner.lock();
        if (ownerPtr)
        {
            cout << "[" << mercenary->name << "]" << ownerPtr->GetName() << "님을 위해 싸우겠습니다.\n";
        }
    }

    while (monster.IsAlive() && player.IsAlive())
    {
        cout << "\n";
        cout << "!!! WARNING: A WILD " << monster.GetName() << " APPEARED !!!\n";

        // 동일한 비율의 게이지 표시 (각자의 MaxHP 대비)
        int pBars = (player.GetHp() * 10) / player.GetMaxHp();
        int gBars = (monster.GetHp() * 10) / monster.GetMaxHp();

        cout << "\n+-----------------------------------------------------------+\n";
        cout << "  monster HP: [";
        for (int i = 0; i < 10; i++) cout << (i < gBars ? "#" : " ");
        cout << "] " << (monster.IsAlive() ? monster.GetHp() : 0) << "  |  YOUR HP: [";
        for (int i = 0; i < 10; i++) cout << (i < pBars ? "#" : " ");
        cout << "] " << (player.IsAlive() ? player.GetHp() : 0) << "\n";
        cout << "+-----------------------------------------------------------+\n";
        cout << " [1] Physical Attack    [2] Critical Attack\n";
        cout << " >> Action : ";
        cin >> action;

        system("cls"); // 매 턴 행동 후 화면 전환

        if (action == 1)
        {
            monster.TakeDamage((int)player.GetAttackDamage()); // 객체 스스로가 데미지를 처리하고 있음
            cout << "\n>> [YOU] attacked the monster for " << (int)player.GetAttackDamage() << " damage!\n";
            
            if (mercenary && monster.IsAlive())
            {
                int mercDmg = mercenary->Attack();
                monster.TakeDamage(mercDmg);
                cout << "\n>> [mercenary] attacked the monster for " << mercDmg << " damage!\n";
            }

            if (monster.IsAlive())
            {
                cout << ">> [monster] counter-attacked! You lost" << monster.Attack() << "HP.\n";
                player.TakeDamage(monster.Attack());
            }
        }
        else if (action == 2)
        {
            player.PreviewCritical();
            monster.TakeDamage(player.CriticalAttack()); // 2배 데미지 받음
            cout << "\n>> [YOU] Critical Hit! " << player.CriticalAttack() << " damage!\n";
            
            if (mercenary && monster.IsAlive())
            {
                int mercDmg = mercenary->Attack();
                monster.TakeDamage(mercDmg);
                cout << ">> [mercenary] attacked the monster for " << mercDmg << " damage!\n";
            }

            if (monster.IsAlive())
            {
                cout << ">> [monster] counter-attacked! You lost " << monster.Attack() << " HP.\n";
                player.TakeDamage(monster.Attack());
            }
        }
        else
        {
            cout << ">> [SYSTEM] You failed to act! The monster strikes! (-" << monster.Attack() << " HP)\n";
            player.TakeDamage(monster.Attack());
        }
    }
    
    // 마지막 전투 메시지 확인 후 결과창으로 전환
    cout << "\n>> Battle ended. Press any key to see the result...\n";
    system("pause");
    system("cls");
    
    return player.IsAlive();
}
