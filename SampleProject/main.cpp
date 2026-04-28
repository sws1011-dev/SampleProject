#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <memory>

#include "Barbarian.h"
#include "Battle.h"
#include "FireGoblin.h"
#include "Monster.h"
#include "Player.h"
#include "Sorceress.h"

using namespace std;

int main()
{
    string userName;
    string charactorClass;
    int classChoiceInput;
    char hardcoreInput;
    bool isHardcore = false;


    // [UI] 타이틀 화면 (아스키 아트 추가)
    cout << "=====================================================\n";
    cout << "       DIABLO STYLE CONSOLE ADVENTURE v1.0         \n";
    cout << "=====================================================\n";
    cout << " >> Input your Hero's name : ";
    cin >> userName;

    cout << "\n-----------------------------------------------------\n";
    cout << " [ SELECT YOUR CLASS ] \n";
    cout << " 1. Amazon      2. Assassin    3. Barbarian    4. Druid\n";
    cout << " 5. Necromancer 6. Paladin     7. Sorceress    8. Warlock\n";
    cout << "-----------------------------------------------------\n";
    cout << " >> Choice : ";
    cin >> classChoiceInput;

    switch (classChoiceInput)
    {
    case 1: charactorClass = "Amazon";
        break;
    case 2: charactorClass = "Assassin";
        break;
    case 3: charactorClass = "Barbarian";
        break;
    case 4: charactorClass = "Druid";
        break;
    case 5: charactorClass = "Necromancer";
        break;
    case 6: charactorClass = "Paladin";
        break;
    case 7: charactorClass = "Sorceress";
        break;
    case 8: charactorClass = "Warlock";
        break;
    default: charactorClass = "Unknown";
        break;
    }

    cout << "\n >> Enable Hardcore Mode? (1: Yes / 2: No) : ";
    cin >> hardcoreInput;
    isHardcore = (hardcoreInput == '1');

    // Player 직업에따라 자식 클래스를 생성
    unique_ptr<Player> playerPtr;
    if (classChoiceInput == 3) playerPtr = make_unique<Barbarian>(userName, isHardcore);
    else if (classChoiceInput == 7) playerPtr = make_unique<Sorceress>(userName, isHardcore);
    else playerPtr = make_unique<Player>(userName, charactorClass, isHardcore);
    Player& player = *playerPtr;

    system("cls"); // 화면 전환

    // [UI] 캐릭터 정보창 (HP/MP 게이지 추가)

    cout << "\n\n";
    cout << "        [ CHARACTER PROFILE ]\n";
    cout << "=====================================================\n";
    cout << " Name   : " << player.GetName() << "\t\tClass : " << player.GetCharacterClass() << "\n";
    cout << " Level  : " << player.GetLevel() << "\t\tMode  : " << (isHardcore ? "HARDCORE" : "STANDARD") << "\n";
    cout << "-----------------------------------------------------\n";
    cout << " [STATS]                 [RESISTANCES]\n";

    int hpBars = (player.GetHp() * 10) / player.GetMaxHp();
    cout << " HP : [";
    for (int i = 0; i < 10; i++) cout << (i < hpBars ? "#" : " ");
    cout << "] " << player.GetHp() << "/" << player.GetMaxHp() << "\t Fire      : " << player.GetFireResist() << "%\n";

    int mpBars = (player.GetMp() * 10) / player.GetMaxMp();
    cout << " MP : [";
    for (int i = 0; i < 10; i++) cout << (i < mpBars ? "*" : " ");
    cout << "] " << player.GetMp() << "/" << player.GetMaxMp() << "\t Lightning : " << player.GetLightningResist() <<
        "%\n";

    cout << " STR: " << player.GetStrength() << " \t\t Cold      : " << player.GetColdResist() << "%\n";
    cout << " DEX: " << player.GetDexterity() << " \t\t Poison    : " << player.GetPoisonResist() << "%\n";
    cout << "-----------------------------------------------------\n";
    cout << " ATK DMG : " << player.GetAttackDamage() << " | ATK SPD : " << player.GetAttackSpeed() << " | MOV SPD : "
        << player.GetMovingSpeed() << "\n";
    cout << "=====================================================\n\n";

    system("pause");
    system("cls"); // 전투 전 화면 전환

    // 전투 시스템    
    int pendingExp = 0;
    vector<unique_ptr<Monster>> monsters;
    monsters.push_back(make_unique<Monster>("Goblin", 50, 0, 15, 0, 50));
    monsters.push_back(make_unique<FireGoblin>("FireGoblin", 50, 0, 15, 0, 50));
    monsters.push_back(make_unique<Monster>("Skeleton", 60, 0, 20, 0, 50));
    monsters.push_back(make_unique<Monster>("Wraith", 50, 0, 25, 0, 50));
    monsters.push_back(make_unique<Monster>("Ghoul", 70, 0, 35, 0, 120));
    monsters.push_back(make_unique<Monster>("Andariel", 200, 0, 150, 0, 500));

    for (auto& monster : monsters)
    {
        if (!player.IsAlive()) break;

        // 전투기능 클래스 구현 이후 전투 생성과 실행
        Battle battle(player, *monster);
        bool battleResult = battle.Run();

        pendingExp += monster->GetExpReward(); // 몬스터 객체 소멸 전 경험치 보상 저장

        // 결과 판정
        cout << "\n=====================================================\n";
        if (!player.IsAlive())
        {
            cout << "             [ !!! YOU ARE DEAD !!! ]                \n";
            if (isHardcore) cout << "        Your journey ends here forever...            \n";
        }
        else
        {
            cout << "             [ VICTORY IN SANCTUARY ]                \n";
            cout << "-----------------------------------------------------\n";

            // 아이템 루팅
            player.Loot();

            // 레벨업
            player.GainExp(pendingExp);
            player.PrintLevel();
        }
    }
    return 0;
}
