#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum class State
{
    Rock,
    Visited,
    NotVisited,
    MAX
};

struct Whale
{
    int r, c;
    // 상 좌 하 우 -> 0 1 2 3
    int d;
};

struct qNode
{
    int r, c;
    string Path;
};

// 상 좌 하 우
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

bool IsIn(int r, int c, int N)
{
    return r > 0 && r <= N && c > 0 && c <= N;
}

bool FirstStep(Whale& whale, vector<vector<State>>& Table)
{
    int N = Table.size() - 1;
    int& r = whale.r;
    int& c = whale.c;
    int& d = whale.d;
    // 현재 방향
    int NewR = r + dy[d], NewC = c + dx[d];
    if (IsIn(NewR, NewC, N))
    {
        if (Table[NewR][NewC] == State::NotVisited)
        {
            r = NewR;
            c = NewC;
            Table[NewR][NewC] = State::Visited;
            return true;
        }
    }

    // 좌회전
    NewR = r + dy[(d + 1) % 4], NewC = c + dx[(d + 1) % 4];
    if (IsIn(NewR, NewC, N))
    {
        if (Table[NewR][NewC] == State::NotVisited)
        {
            r = NewR;
            c = NewC;
            d = (whale.d + 1) % 4;
            Table[NewR][NewC] = State::Visited;
            return true;
        }
    }

    // 우회전
    NewR = r + dy[(d + 3) % 4], NewC = c + dx[(d + 3) % 4];
    if (IsIn(NewR, NewC, N))
    {
        if (Table[NewR][NewC] == State::NotVisited)
        {
            r = NewR;
            c = NewC;
            d = (whale.d + 3) % 4;
            Table[NewR][NewC] = State::Visited;
            return true;
        }
    }

    // 반대
    NewR = r + dy[(d + 2) % 4], NewC = c + dx[(d + 2) % 4];
    if (IsIn(NewR, NewC, N))
    {
        if (Table[NewR][NewC] == State::NotVisited)
        {
            r = NewR;
            c = NewC;
            d = (whale.d + 2) % 4;
            Table[NewR][NewC] = State::Visited;
            return true;
        }
    }

    return false;
}

bool SecondStep(Whale& whale, vector<vector<State>>& Table)
{
    // 상 좌 하 우
    static char PathDir[4] = {'U', 'L', 'D', 'R'};

    // 문제의 경로 우선순위: 좌 하 우 상
    static int order[4] = {1, 2, 3, 0};

    int N = Table.size() - 1;
    int DestR, DestC;

    string OptPath(3000, 'U');

    vector<vector<bool>> Visited(
        N + 1,
        vector<bool>(N + 1, false)
    );

    queue<qNode> q;

    q.push({whale.r, whale.c, ""});
    Visited[whale.r][whale.c] = true;

    while (!q.empty())
    {
        int r = q.front().r;
        int c = q.front().c;
        string Path = move(q.front().Path);
        q.pop();

        // 아직 방문하지 않은 바다 발견
        if (Table[r][c] == State::NotVisited)
        {
            if (Path.size() < OptPath.size())
            {
                DestR = r;
                DestC = c;
                OptPath = move(Path);
            }
            else if (Path.size() == OptPath.size())
            {
                // 행 우선
                if (r < DestR)
                {
                    DestR = r;
                    DestC = c;
                    OptPath = move(Path);
                }
                // 열 우선
                else if (r == DestR && c < DestC)
                {
                    DestR = r;
                    DestC = c;
                    OptPath = move(Path);
                }
            }

            continue;
        }

        // 좌 -> 하 -> 우 -> 상
        for (int k = 0; k < 4; k++)
        {
            int i = order[k];

            int NewR = r + dy[i];
            int NewC = c + dx[i];

            if (!IsIn(NewR, NewC, N))
                continue;

            if (Table[NewR][NewC] == State::Rock)
                continue;

            if (Visited[NewR][NewC])
                continue;

            Visited[NewR][NewC] = true;

            Path.push_back(PathDir[i]);
            q.push({NewR, NewC, Path});
            Path.pop_back();
        }
    }

    if (OptPath.size() == 3000)
        return false;

    // 선택된 경로대로 실제 이동
    for (char dir : OptPath)
    {
        if (dir == 'L')
        {
            whale.c--;
            whale.d = 1;
        }
        else if (dir == 'R')
        {
            whale.c++;
            whale.d = 3;
        }
        else if (dir == 'U')
        {
            whale.r--;
            whale.d = 0;
        }
        else // D
        {
            whale.r++;
            whale.d = 2;
        }

        Table[whale.r][whale.c] = State::Visited;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c, d;
    cin >> N >> r >> c >> d;
    Whale whale;
    whale.r = r;
    whale.c = c;
    if (d == 1)
    {
        whale.d = 0;
    }
    else if (d == 2)
    {
        whale.d = 2;
    }
    else if (d == 3)
    {
        whale.d = 1;
    }
    else
    {
        whale.d = 3;
    }

    vector<vector<State>> Table(N + 1, vector<State>(N + 1));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int V;
            cin >> V;
            if (V == 0)
            {
                Table[i][j] = State::NotVisited;
            }
            else
            {
                Table[i][j] = State::Rock;
            }
        }
    }

    Table[whale.r][whale.c] = State::Visited;
    cout << whale.r << " " << whale.c << '\n'; 

    while (1)
    {
        // 1단계
        if (FirstStep(whale, Table))
        {
            cout << whale.r << " " << whale.c << '\n';
            continue;
        }

        if (SecondStep(whale, Table))
        {
            cout << whale.r << " " << whale.c << '\n';
            continue;
        }

        break;
    }

    return 0;
}