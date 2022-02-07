#include <cstdio>
#include <queue>

int arr[200000][3];

struct Node
{
    int label, frequency;

    Node(int a, int b)
    {
        label = a,
        frequency = b;
    }
};

int calcWeight(int num, int weight)
{
    if (arr[num][1] == -1)
        return weight * arr[num][0];
    else
        return calcWeight(arr[num][1], weight + 1) + calcWeight(arr[num][2], weight + 1);
}

bool operator<(const Node &n1, const Node &n2)
{
    return n1.frequency > n2.frequency;
}

int main(void)
{
    int T = 0, N = 0;
    while (~scanf("%i", &T))
    {
        std::priority_queue<Node> Q;
        for (int i = 0; i < T; i++)
        {
            scanf("%d", &N);
            Q.emplace(Node(i, N));
            arr[i][0] = N;
            arr[i][1] = arr[i][2] = -1;
        }
        while (true)
        {
            Node n1 = Q.top();
            Q.pop();

            if (Q.empty())
                break;

            Node n2 = Q.top();
            Q.pop();

            Q.emplace(Node(T, n1.frequency + n2.frequency));
            arr[T][0] = n1.frequency + n2.frequency;
            arr[T][1] = n1.label;
            arr[T++][2] = n2.label;
        }

        printf("%i\n", calcWeight(T - 1, 0));
    }
}