#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    bool bRobot;
    int p;

    bool CanGo() const
    {
        return (p >= 0 && !bRobot);
    };
};

struct Robot
{
    int R, C;
};

struct qNode
{
    int R, C, Dist;
};

int PrintTotalDust(const vector<vector<Node>>& Table)
{
    int Res = 0, N = Table.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            if (Table[i][j].p > 0)
            {
                Res += Table[i][j].p;
            }
        }
    }
    
    return Res;
}

void Move(vector<vector<Node>>& Table, Robot& robot)
{
    int N = Table.size();
    vector<vector<bool>> Visited(N, vector<bool>(N));
    queue<qNode> q;
    q.push({robot.R, robot.C, 0});
    Visited[robot.R][robot.C] = true;

    int DestR, DestC, MinDist = 123456789;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while (!q.empty())
    {
        int R = q.front().R, C = q.front().C, Dist = q.front().Dist;
        q.pop();

        if (Table[R][C].p > 0)
        {
            if (Dist < MinDist)
            {
                DestR = R;
                DestC = C;
                MinDist = Dist;
            }
            else if (Dist == MinDist)
            {
                if (R < DestR)
                {
                    DestR = R;
                    DestC = C;
                }
                else if (R == DestR)
                {
                    if (C < DestC)
                    {
                        DestC = C;
                    }
                }
            }
            continue;
        }

        if (Dist > MinDist)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int NewR = R + dx[i], NewC = C + dy[i];
            if (NewR >= 0 && NewR < N && NewC >= 0 && NewC < N)
            {
                if (!Visited[NewR][NewC] && Table[NewR][NewC].p != -1 && !Table[NewR][NewC].bRobot)
                {
                    Visited[NewR][NewC] = true;
                    q.push({NewR, NewC, Dist + 1});
                }
            }
        }
    }

    if (MinDist == 123456789)
    {
        return;
    }

    Table[robot.R][robot.C].bRobot = false;
    robot.R = DestR;
    robot.C = DestC;
    Table[DestR][DestC].bRobot = true;
}

void FirstStep(vector<vector<Node>>& Table, vector<Robot>& Robots)
{
    for (Robot& robot : Robots)
    {
        Move(Table, robot);
    }
}

void Clean(vector<vector<Node>>& Table, Robot& robot)
{
    int N = Table.size();
    int MaxRemove = 0, DirIdx = 0;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    for (int NotIdx = 0; NotIdx < 4; NotIdx++)
    {
        int Remove = 0; 
        for (int i = 0; i < 4; i++)
        {
            if (NotIdx == i)
            {
                continue;
            }

            int NewR = robot.R + dy[i], NewC = robot.C + dx[i];
            if (NewR >= 0 && NewR < N && NewC >= 0 && NewC < N)
            {
                if (Table[NewR][NewC].p > 0)
                {
                    Remove += min(20, Table[NewR][NewC].p);
                }
            }
        }

        if (Remove > MaxRemove)
        {
            DirIdx = NotIdx;
            MaxRemove = Remove;
        }
    }

    Table[robot.R][robot.C].p -= min(20, Table[robot.R][robot.C].p);
    for (int i = 0; i < 4; i++)
    {
        if (DirIdx == i)
        {
            continue;
        }

        int NewR = robot.R + dy[i], NewC = robot.C + dx[i];
        if (NewR >= 0 && NewR < N && NewC >= 0 && NewC < N)
        {
            if (Table[NewR][NewC].p > 0)
            {
                Table[NewR][NewC].p -= min(20, Table[NewR][NewC].p);
            }
        }
    }
}

void SecondStep(vector<vector<Node>>& Table, vector<Robot>& Robots)
{
    for (Robot& robot : Robots)
    {
        Clean(Table, robot);
    }
}

void ThirdStep(vector<vector<Node>>& Table)
{
    int N = Table.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Table[i][j].p > 0)
            {
                Table[i][j].p += 5;
            }
        }
    }
}

void FourthStep(vector<vector<Node>>& Table)
{
    int N = Table.size();
    vector<vector<Node>> Next = Table;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Table[i][j].p == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    int NewR = i + dx[k], NewC = j + dy[k];
                    if (NewR >= 0 && NewR < N && NewC >= 0 && NewC < N)
                    {
                        if (Table[NewR][NewC].p > 0)
                        {
                            Next[i][j].p += Table[NewR][NewC].p;
                        }
                    }
                }
                Next[i][j].p /= 10;
            }
        }
    }

    Table = Next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N >> K >> L;

    vector<vector<Node>> Table(N, vector<Node>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0;j < N; j++)
        {
            cin >> Table[i][j].p;
        }
    }

    vector<Robot> Robots(K);
    for (int i = 0; i < K; i++)
    {
        cin >> Robots[i].R >> Robots[i].C;
        Robots[i].R--;
        Robots[i].C--;
        Table[Robots[i].R][Robots[i].C].bRobot = true;
    }

    for (int test_case = 1; test_case <= L; test_case++)
    {
        FirstStep(Table, Robots);
        SecondStep(Table, Robots);
        ThirdStep(Table);
        FourthStep(Table);

        int Res = PrintTotalDust(Table);
        cout << Res << '\n';
        if (Res == 0)
        {
            break;
        }
    }

    return 0;
}