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
    class Player : Creature
    {
        protected PlayerType type = PlayerType.None;

        protected Player(PlayerType type): base(CreatureType.Player)
        {
            this.type = type;
        }


        
        

        
    }
   
}