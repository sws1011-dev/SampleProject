#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Call By Value: 복사본 전달 -> 원본은 변경 불가
void PreviewCritical(float attackDamage)
{
    attackDamage *= 2; // Parameter 복사본만 2배, 원본 변수는 그대로
    cout << "크리티컬 예상 데미지:" << attackDamage << "\n";
}

// Call By Reference: 예시) 참조자 전달 -> 실제 크리티컬 데미지 적용
void ApplyCriticalDamage(float attackDamage)
{
    int critDamage = (int)(attackDamage * 2); // 치명타는 2배 데미지 적용
}

// Call By Reference: 참조자 전달 -> * 없이 직접 수정
void LevelUpRef(int& level)
{
    level++;
}

// const 참조자 : 복사 비용 절약 + 원본 수정 차단
void PrintLevel(const int& level)
{
    cout << "현재 레벨: " << level << "\n";
    //level++; // 컴파일 오류발생, const라 원본의 수정이 불가능함
}

// Monster 클래스
class Monster
{
private:
    int hp, maxHp;
    int attackDamage;

public:
    Monster(int initHp, int atk) : hp(initHp), maxHp(initHp), attackDamage(atk)
    {
        cout << "[몬스터 등장!] HP: " << hp << " / ATK: " << attackDamage << "\n";
    }

    ~Monster()
    {
        cout << "[몬스터 소멸!]\n"; // 소멸자 확인용 로그
    }

    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    bool IsAlive() const { return hp > 0; }

    void TakeDamage(int damage) // 몬스터가 피해를 받음
    {
        hp -= damage;
        if (hp < 0) hp = 0; // 음수 방지
    }

    int Attack() const { return attackDamage; } // 몬스터가 플레이어를 공격
};

// Player 클래스
class Player
{
private:
    // 기본 정보
    string name;
    string charactorClass;
    bool isHardcore;

    // 기본 능력치
    int strength, dexterity, vitality, energy;

    //파생 능력치
    int level;
    int hp, maxHp, mp, maxMp;
    float attackDamage;
    float attackSpeed;
    double movingSpeed;

    // 저항 능력치
    int fireResist, lightningResist, coldResist, poisonResist;

    // 인벤토리
    int inventory[5];

public:
    Player(const string& name, const string& characterClass, bool isHardCore) : // 외부입력 값 세팅 초기화
        name(name), charactorClass(characterClass), isHardcore(isHardCore), // 단순 값 세팅 초기화
        strength(50), dexterity(50), vitality(50), energy(50),
        level(1),
        fireResist(0), lightningResist(0), coldResist(0), poisonResist(0)
    {
        maxHp = vitality * 2; // 계산이 필요한 값 세팅
        hp = maxHp;
        maxMp = (int)(energy * 1.5);
        mp = maxMp;
        attackDamage = strength * 0.2f;
        attackSpeed = dexterity / 10.0f;
        movingSpeed = dexterity / 30.0f;
        for (int i = 0; i < 5; i++) inventory[i] = 0;
    }

    // Getters
    string GetName() const { return name; }
    string GetCharacterClass() const { return charactorClass; }
    bool IsHardcore() const { return isHardcore; }
    int GetStrength() const { return strength; }
    int GetDexterity() const { return dexterity; }
    int GetVitality() const { return vitality; }
    int GetEnergy() const { return energy; }
    int GetLevel() const { return level; }
    int GetHp() const { return hp; }
    int GetMaxHp() const { return maxHp; }
    int GetMp() const { return mp; }
    int GetMaxMp() const { return maxMp; }
    float GetAttackDamage() const { return attackDamage; }
    float GetAttackSpeed() const { return attackSpeed; }
    double GetMovingSpeed() const { return movingSpeed; }
    int GetFireResist() const { return fireResist; }
    int GetLightningResist() const { return lightningResist; }
    int GetColdResist() const { return coldResist; }
    int GetPoisonResist() const { return poisonResist; }

    int* GetInventory() { return inventory; }

    // 기능(함수)
    bool IsAlive() const { return hp > 0; }

    void TakeDamage(int damage)
    {
        hp -= damage;
        if (hp <= 0) hp = 0;
    }

    int Attack() const { return (int)attackDamage; }
    int CriticalAttack() const { return (int)(attackDamage * 2); }
    void LevelUp() { level++; }

    void PreviewCritical() const
    {
        float preview = attackDamage * 2;
        cout << "크리티컬 예상 데미지: " << preview << "\n";
    }

    void PrintLevel() const
    {
        cout << "현재 레벨: " << level << "\n";
    }
};

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
    // 생성자 호출
    Monster goblin(30, 10);

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
    player.LevelUp();
    player.PrintLevel();

    return 0;
}
