using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSharp
{
    public enum PlayerType
    {
        None = 0,
        Knight = 1,
        Archer = 2,
        Mage = 3
    }
    internal class Player
    {
        protected PlayerType type = PlayerType.None;
        protected int hp = 0; 
        protected int attack = 0;

        protected Player(PlayerType type)
        {
            this.type = type;
        }
        public void SetInfo(int hp, int attack)
        {
            this.hp = hp;
            this.attack = attack;
        }
        public int GetHP() { return hp; }
        public int GetAttack() { return attack; }
    }

    class Knight : Player
    {
        public Knight() : base(PlayerType.Knight)
        {

            type = PlayerType.Knight;
            SetInfo(100, 10);
            Console.WriteLine(GetHP());
            Console.WriteLine(GetAttack());
        }
    }
    class Archer: Player
    {
        public Archer(): base(PlayerType.Archer)
        {
            type = PlayerType.Archer;
        }
    }
}
