using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using CSharp;

class Knight : Player
{
    public Knight() : base(PlayerType.Knight)
    {
        type = PlayerType.Knight;
        SetInfo(100, 10);
    }

}