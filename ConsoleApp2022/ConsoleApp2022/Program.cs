// See https://aka.ms/new-console-template for more information

ClassType choice = ClassType.None;
while (choice == ClassType.None)
{
    choice = ChooseClass();
    if(choice != ClassType.None)
    {
        // 캐릭터 생성
        // CreatePlayer()
        Player player;
        
        
        CreatePlayer(choice, out player);
        //Console.WriteLine($"HP{player.hp} Attack{player.attack}");
        // 기사(100/10) 궁수(75/12) 법사(50/15)
        EnterGame(player);

    }
}

static void Fight(ref Player player, ref Monster monster)
{
    while (true)
    {
        // 플레이어가 몬스터 공격
        monster.hp -= player.attack;
        if(monster.hp <= 0)
        {
            Console.WriteLine("승리했습니다!");
            Console.WriteLine($"남은 체력 : {player.hp}");
            break;
        }

        // 몬스터가 플레이어 공격
        player.hp -= monster.attack;
        if(player.hp <= 0)
        {
            Console.WriteLine("패배했습니다");
            break;
        }
    }
}

static void EnterField(ref Player player)
{
    while (true)
    {
        Monster monster;

        CreateRandomMonster(out monster);
        Console.WriteLine("[1] 전투 모드");
        Console.WriteLine("[2] 도망");
        string input = Console.ReadLine();
        if (input == "1")
        {
            Fight(ref player, ref monster);
        }
        else if (input == "2")
        {
            Random rand = new Random();
            int randValue = rand.Next(0, 101);
            if (randValue <= 33)
            {
                Console.WriteLine("도망쳤습니다 !");
                return;
            }
            else
            {
                Console.WriteLine("도망치지 못하고 싸웁니다!");
                Fight(ref player, ref monster);
            }
        }
    }
}

static void EnterGame(Player player)
{
    Console.WriteLine("게임에 접속했습니다.");
    Console.WriteLine("[1] 필드로 간다");
    Console.WriteLine("[2] 로비로 돌아가기");

    while (true)
    {
        string input = Console.ReadLine();
        switch (input)
        {
            case "1":
                EnterField(ref player);
                break;
            case "2":
                return;
        }
    }
}
static void CreatePlayer(ClassType choice, out Player player)
{
    player.hp = 0;
    player.attack = 0;
    switch (choice)
    {
        case ClassType.Knight:
            player.hp = 100;
            player.attack = 10;
            break;
        case ClassType.Archer:
            player.hp = 75;
            player.attack = 12;
            break;
        case ClassType.Mage:
            player.hp = 50;
            player.attack = 15;
            break;
        default:
            player.hp = 0;
            player.attack = 0;
            break;

    }
}

static void CreateRandomMonster(out Monster monster)
{
    monster.hp = 0;
    monster.attack = 0;
    Random rand = new Random();
    int randMonster = rand.Next(1, 4);
    switch (randMonster)
    {
        case (int)MonsterType.Slime:
            Console.WriteLine("슬라임이 스폰되었습니다!");
            monster.hp = 20;
            monster.attack = 2;
            break;
        case (int)MonsterType.Orc:
            Console.WriteLine("오크가 스폰되었습니다!");
            monster.hp = 40;
            monster.attack = 4;
            break;
        case (int)MonsterType.Skeleton:
            Console.WriteLine("스켈레톤이 스폰되었습니다!");
            monster.hp = 30;
            monster.attack = 3;
            break;
        default:
            Console.WriteLine("아무것도 스폰되지 않았습니다!");
            monster.hp = 0;
            monster.attack = 0;
            break;

    }
}

static ClassType ChooseClass()
{

    Console.WriteLine("직업을 선택하세요!");
    Console.WriteLine("[1] 기사");
    Console.WriteLine("[2] 궁수");
    Console.WriteLine("[3] 법사");
    ClassType choice = ClassType.None;
    string input = Console.ReadLine();
    switch (input)
    {
        case "1":
            choice = ClassType.Knight;
            break;
        case "2":
            choice = ClassType.Archer;
            break;
        case "3":
            choice = ClassType.Mage;
            break;
    }
    return choice;
}

enum ClassType
{
    None = 0,
    Knight = 1,
    Archer = 2,
    Mage = 3
}

enum MonsterType
{
    None = 0,
    Slime = 1,
    Orc = 2,
    Skeleton = 3
}

struct Player
{
    public int hp;
    public int attack;
}

struct Monster
{
    public int hp;
    public int attack;
}

