#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Monster.h"
#include "Player.h"

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

    // Player 객체 생성 - 입력받은 값들로 초기화, 스탯은 내부에서 자동 계산됨
    Player player(userName, charactorClass, isHardcore);

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
    cout << "] " << player.GetMp() << "/" << player.GetMaxMp() << "\t Lightning : " << player.GetLightningResist() << "%\n";

    cout << " STR: " << player.GetStrength() << " \t\t Cold      : " << player.GetColdResist() << "%\n";
    cout << " DEX: " << player.GetDexterity() << " \t\t Poison    : " << player.GetPoisonResist() << "%\n";
    cout << "-----------------------------------------------------\n";
    cout << " ATK DMG : " << player.GetAttackDamage() << " | ATK SPD : " << player.GetAttackSpeed() << " | MOV SPD : " << player.GetMovingSpeed() << "\n";
    cout << "=====================================================\n\n";

    system("pause");
    system("cls"); // 전투 전 화면 전환

    // 전투 시스템    
    int pendingExp = 0;
    {
        // 생성자 호출
        Monster goblin(50, 0, 15, 0, 50);

        int action;

        while (goblin.IsAlive() && player.IsAlive())
        {
            cout << "\n";
            cout << "!!! WARNING: A WILD GOBLIN APPEARED !!!\n";

            // 동일한 비율의 게이지 표시 (각자의 MaxHP 대비)
            int pBars = (player.GetHp() * 10) / player.GetMaxHp();
            int gBars = (goblin.GetHp() * 10) / goblin.GetMaxHp();

            cout << "\n+-----------------------------------------------------------+\n";
            cout << "  GOBLIN HP: [";
            for (int i = 0; i < 10; i++) cout << (i < gBars ? "#" : " ");
            cout << "] " << (goblin.IsAlive() ? goblin.GetHp() : 0) << "  |  YOUR HP: [";
            for (int i = 0; i < 10; i++) cout << (i < pBars ? "#" : " ");
            cout << "] " << (player.IsAlive() ? player.GetHp() : 0) << "\n";
            cout << "+-----------------------------------------------------------+\n";
            cout << " [1] Physical Attack    [2] Critical Attack\n";
            cout << " >> Action : ";
            cin >> action;

            system("cls"); // 매 턴 행동 후 화면 전환

            if (action == 1)
            {
                cout << "\n>> [YOU] attacked the Goblin for " << (int)player.GetAttackDamage() << " damage!\n";
                goblin.TakeDamage((int)player.GetAttackDamage()); // 객체 스스로가 데미지를 처리하고 있음

                if (goblin.IsAlive())
                {
                    cout << ">> [GOBLIN] counter-attacked! You lost" << goblin.Attack() << "HP.\n";
                    player.TakeDamage(goblin.Attack());
                }
            }
            else if (action == 2)
            {
                player.PreviewCritical();
                goblin.TakeDamage(player.CriticalAttack()); // 2배 데미지 받음
                cout << "\n>> [YOU] Critical Hit! " << player.CriticalAttack() << " damage!\n";

                if (goblin.IsAlive())
                {
                    cout << ">> [GOBLIN] counter-attacked! You lost " << goblin.Attack() << " HP.\n";
                    player.TakeDamage(goblin.Attack());
                }
            }
            else
            {
                cout << ">> [SYSTEM] You failed to act! The Goblin strikes! (-" << goblin.Attack() << " HP)\n";
                player.TakeDamage(goblin.Attack());
            }
        }

        // 마지막 전투 메시지 확인 후 결과창으로 전환
        cout << "\n>> Battle ended. Press any key to see the result...\n";
        system("pause");
        system("cls");
    
        pendingExp += goblin.GetExpReward(); // 몬스터 객체 소멸 전 경험치 보상 저장
    }
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

        srand((unsigned int)time(NULL));
        cout << " [LOOT FOUND]\n";

        int* invPtr = player.GetInventory(); // invPtr -> gameInventory 시작 주소 [0]

        // 포인터로 인벤토리에 랜덤 숫자 저장
        for (int i = 1; i <= 3; i++)
        {
            *invPtr = rand() % 4 + 1; // 역참조로 현재 칸에 아이템 코드를 저장하고자 함
            invPtr++;
        }

        // 포인터 순회로 인벤토리 출력(5칸)
        invPtr = player.GetInventory(); // invPtr 처음 주소로 리셋
        int slot = 0;
        cout << "=====================================================\n";
        cout << "\t\tINVENTORY\n";
        cout << "=====================================================\n";
        while (invPtr < player.GetInventory() + 5)
        {
            string itemName;
            if (*invPtr == 1) itemName = "Gold";
            else if (*invPtr == 2) itemName = "Healing Potion";
            else if (*invPtr == 3) itemName = "Weapon";
            else if (*invPtr == 4) itemName = "Armor";
            else itemName = "None";
            cout << slot++ << ". " << itemName << "\n";
            invPtr++;
        }
    }
    cout << "=====================================================\n";

    // 레벨업
    player.GainExp(pendingExp);
    player.PrintLevel();

    return 0;
}
