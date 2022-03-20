using System.Net.Sockets;
using System.Net;
using System.Text;
using ServerCore;

namespace Server
{
    class Programs
    {
        static Listener _listener = new Listener();
        public static GameRoom Room = new GameRoom();

        static void Main(string[] args)
        {

            string host = Dns.GetHostName();
            IPHostEntry ipHost = Dns.GetHostEntry(host);
            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint endPoint = new IPEndPoint(ipAddr, 7777);
            _listener.Init(endPoint, () => { return SessionManager.Instance.Generate(); });

            while (true)
            {
                Console.WriteLine("Listening...");
                Thread.Sleep(1000);
            }

        }
    }
}