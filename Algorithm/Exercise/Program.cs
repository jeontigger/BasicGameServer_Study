// See https://aka.ms/new-console-template for more information
Stack<int> stack = new Stack<int>();

stack.Push(101);
stack.Push(102);
stack.Push(103);
stack.Push(104);
stack.Push(105);

int data = stack.Peek();

Queue<int> queue = new Queue<int>();

LinkedList<int> ll = new LinkedList<int>();

Graph graph = new Graph();
graph.Dijikstra(0);
class Graph
{
    int[,] adj = new int[6, 6]
    {
        { -1, 15, -1, 35, -1, -1 },
        { 15, -1, 5, 10, -1, -1 },
        { -1, 5, -1, -1, -1, -1 },
        { 35, 10, -1, -1, 5, -1 },
        { -1, -1, -1, 5, -1, 5 },
        { -1, -1, -1, -1, 5, -1 },
    };

    List<int>[] adj2 = new List<int>[]
    {
        new List<int> () { 1, 3 },
        new List<int> () { 0, 2, 3 },
        new List<int> () { 1 },
        new List<int> () { 0, 1, 4 },
        new List<int> () { 3, 5 },
        new List<int> () { 4 },
    };
    bool[] visited = new bool[6];
    public void Dijikstra(int start)
    {
        bool[] visited = new bool[6];
        int[] distance = new int[6];
        int[] parent = new int[6];

        Array.Fill(distance, Int32.MaxValue);

        distance[start] = 0;
        parent[start] = start;

        while (true)
        {
            // 제일 좋은 후보를 찾는다

            // 가장 유력한 후보의 거리와 번호를 저장한다
            int closest = Int32.MaxValue;
            int now = -1;

            for (int i = 0; i < 6; i++)
            {
                // 이미 방문한 정점은 스킵
                if (visited[i])
                    continue;
                if (distance[i] == Int32.MaxValue || distance[i] >= closest)
                    continue;
                // 여태껏 발견한 가장 좋은 후보
                closest = distance[i];
                now = i;
            }
            if (now == -1)
                break;
            visited[now] = true;
            for(int next = 0; next < 6; next++)
            {
                if (adj[now, next] == -1)
                    continue;
                if (visited[next])
                    continue;

                // 새로 조사된 정점의 최단거리를 계산한다
                int nextDist = distance[now] + adj[now, next];
                if (nextDist < distance[next])
                {
                    distance[next] = nextDist;
                    parent[next] = now;
                }
            }
        }
    }
    public void BFS(int start)
    {
        bool[] found = new bool[6];

        Queue<int> q = new Queue<int>();
        q.Enqueue(start);
        found[start] = true;

        while (q.Count > 0)
        {
            int now = q.Dequeue();
            Console.WriteLine(now);

            for(int next = 0; next < 6; next++)
            {
                if (adj[now, next] == 0)
                    continue;
                if (found[next])
                    continue;
                q.Enqueue(next);
                found[next] = true;
            }
        }
    }

    public void DFS(int now)
    {
        // 1. 우선 now 부터 방문,
        Console.WriteLine(now);
        visited[now] = true;
        // 2. 연결된 정점 확인, [미방문 상태 노드] 방문
        for(int next = 0; next < 6; next++)
        {
            // 연결 되어있지 않으면 스킵
            if(adj[now, next] == 0)
                continue;
            // 방문했으면 스킵
            if (visited[next])
                continue;
            DFS(next);

        }
    }
    public void DFS2(int now)
    {
        Console.WriteLine(now);
        visited[now] = true;

        foreach(int next in adj2[now])
        {
            if (visited[next])
                continue;
            DFS2(next);
        }

    }
    public void SearchAll()
    {
        visited = new bool[6];
        for(int now = 0;now<6; now++)
        {
            if (visited[now] == false)
                DFS(now);
        }
    }
}