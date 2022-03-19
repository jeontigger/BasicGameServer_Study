﻿using Server;
using ServerCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

internal class PacketHandler
{
    public static void C_ChatHandler(PacketSession session, IPacket packet)
    {
        C_Chat chatPacket = packet as C_Chat;
        ClientSession clientSession = session as ClientSession;

        if (clientSession.Room == null)
            return;
        clientSession.Room.Broadcast(clientSession, chatPacket.chat);

        foreach (C_PlayerInfoReq.Skill skill in p.skills)
        {
            Console.WriteLine($"Skill({skill.id})({skill.level})({skill.duration})");
        }
    }

}