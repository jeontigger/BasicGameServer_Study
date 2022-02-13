// See https://aka.ms/new-console-template for more information
Stack<int> stack = new Stack<int>();
Queue<int> queue = new Queue<int>();
LinkedList<int> ll = new LinkedList<int>();
Graph graph = new Graph();

TreeNode<string> root = MakeTree();

PriorityQueue<Knight> q = new PriorityQueue<Knight>();
q.Push(new Knight() { Id = 20});
q.Push(new Knight() { Id = 10 });
q.Push(new Knight() { Id = 30 });
q.Push(new Knight() { Id = 90 });
q.Push(new Knight() { Id = 40 });
while (q.Count() > 0)
{
    Console.WriteLine(q.pop().Id);
}
Console.WriteLine("hello");


static int GetHeight(TreeNode<string> root)
{
    int height = 0;
    foreach(TreeNode<string> child in root.Children)
    {
        int newHeight = GetHeight(child) + 1;
        height = Math.Max(height, newHeight);
    }

    return height;
}
static TreeNode<string> MakeTree()
{
    TreeNode<string> root = new TreeNode<string>() { Data = "R1 개발실" };
    {
        {
            TreeNode<string> node = new TreeNode<string>() { Data = "디자인팀" };
            node.Children.Add(new TreeNode<string>() { Data = "전투" });
            node.Children.Add(new TreeNode<string>() { Data = "경제" });
            node.Children.Add(new TreeNode<string>() { Data = "스토리" });
            root.Children.Add(node);
        }
        {
            TreeNode<string> node = new TreeNode<string>() { Data = "프로그래밍팀" };
            node.Children.Add(new TreeNode<string>() { Data = "서버" });
            node.Children.Add(new TreeNode<string>() { Data = "클라" });
            node.Children.Add(new TreeNode<string>() { Data = "엔진" });
            root.Children.Add(node);
        }
        {
            TreeNode<string> node = new TreeNode<string>() { Data = "아트팀" };
            node.Children.Add(new TreeNode<string>() { Data = "배경" });
            node.Children.Add(new TreeNode<string>() { Data = "캐릭터" });
            root.Children.Add(node);
        }
    }
    return root;
}

static void PrintTree(TreeNode<string> root)
{
    Console.WriteLine(root.Data);
    foreach (TreeNode<string> child in root.Children)
        PrintTree(child);
}
class Knight: IComparable<Knight>
{
    public int Id { get; set; }
    public int CompareTo(Knight other)
    {
        if (Id == other.Id)
            return 0;
        return Id > other.Id ? 1 : -1;
    }
}
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
class TreeNode<T>
{
    public T Data { get; set; }
    public List<TreeNode<T>> Children { get; set; } = new List<TreeNode<T>>();
}
class PriorityQueue<T> where T : IComparable<T>
{
    List<T> _heap = new List<T>();

    public void Push(T data) 
    {
        // 힙의 맨 끝에 새로운 데이터를 삽입한다
        _heap.Add(data);

        int now = _heap.Count - 1;
        while (now > 0)
        {
            int next = (now - 1) / 2;
            if (_heap[now].CompareTo(_heap[next])<0)
                break;

            T temp = _heap[now];
            _heap[now] = _heap[next];
            _heap[next] = temp;
            now = next;
        }
    }
    public T pop() {
        T ret = _heap[0];
        int lastIndex = _heap.Count - 1;
        _heap[0] = _heap[lastIndex];
        _heap.RemoveAt(lastIndex);
        lastIndex--;

        int now = 0;
        while (true)
        {
            int left = 2 * now + 1;
            int right = 2 * now + 2;

            int next = now;

            if (left <= lastIndex && _heap[next].CompareTo(_heap[left]) < 0)
                next = left;
            if (right <= lastIndex && _heap[next].CompareTo(_heap[right]) < 0)
                next = right;
            if (next == now)
                break;

            T temp = _heap[now];
            _heap[now] = _heap[next];
            _heap[next] = temp;
            now = next;
        }
        return ret;
    }
    public int Count()
    {
        return _heap.Count;
    }

}