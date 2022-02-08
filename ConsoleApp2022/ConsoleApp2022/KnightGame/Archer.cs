using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CSharp;

class Archer : Player
{
    public Archer() : base(PlayerType.Archer)
    {
        type = PlayerType.Archer;
        
        SetInfo(100, 10);
    }

}