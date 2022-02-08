using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CSharp;

class Mage : Player
{
    public Mage() : base(PlayerType.Mage)
    {
        type = PlayerType.Mage;
        SetInfo(100, 10);
    }

}