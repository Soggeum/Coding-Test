#include<vector>
#include <queue>

using namespace std;

struct Node
{
    int R, C;
    int Count;      
};

bool CanGo(int R, int C, const vector<vector<int>>& maps, const vector<vector<bool>>& visited)
{
    if (!(R < maps.size() && R >= 0))
    {
        return false;
    }
    if (!(C < maps[0].size() && C >= 0))
    {
        return false;
    }
    if (maps[R][C] == 0)
    {
        return false;
    }
    if (visited[R][C])
    {
        return false;
    }
    
    return true;
}

int solution(vector<vector<int>> maps)
{
    int N = maps.size(), M = maps[0].size();
    
    Node Start = {0, 0, 1};
    queue<Node> Q;
    Q.push(Start);
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    while(!Q.empty())
    {
        Node Front = Q.front();
        Q.pop();
        if (Front.R == N - 1 && Front.C == M - 1)
        {
            return Front.Count;
        }
        
        for (int i = 0; i < dx.size(); i++)
        {
            int NextC = Front.C + dx[i];
            int NextR = Front.R + dy[i];
            if (CanGo(NextR, NextC, maps, visited))
            {
                Q.push({NextR, NextC, Front.Count + 1});
                visited[NextR][NextC] = true;
            }
        }
    }
    
    return -1;
}