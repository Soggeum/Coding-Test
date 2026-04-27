#include <string>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Node
{
    int Row, Col;
    int Cost;
    int Dir;    // 'Vertical' = 0, "horizontal" = 1
    
    bool operator<(const Node& other) const
    {
        return this->Cost > other.Cost;
    }
};

bool CanGo(int Row, int Col, const vector<vector<int>>& board)
{
    int N = board.size();
    if (Row < 0 || Row >= N || Col < 0 || Col >= N)
    {
        return false;
    }
    if (board[Row][Col] == 1)
    {
        return false;
    }
    return true;
}

void CalculateCost(int& Cost, int i, int& Dir)
{
    if (Dir == 0) 
    {
        if (i < 2)
        {
            Cost += 100 + 500;
            Dir = 1;
        }
        else
        {
            Cost += 100;
            Dir = 0;
        }
    }
    else
    {
        if (i < 2)
        {
            Cost += 100;
            Dir = 1;
        }
        else
        {
            Cost += 100 + 500;
            Dir = 0;
        }
    }
}

int solution(vector<vector<int>> board) {
    priority_queue<Node> pq;
    pq.push({0, 0, 0, 0});
    pq.push({0, 0, 0, 1});
    
    int N = board.size();
    vector<vector<vector<int>>> Visited(N, vector<vector<int>>(N, vector<int>(2, numeric_limits<int>::max())));
    Visited[0][0][0] = 0;
    Visited[0][0][1] = 0;
    
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    while(!pq.empty())
    {
        int Row = pq.top().Row;
        int Col = pq.top().Col;
        int Cost = pq.top().Cost;
        int Dir = pq.top().Dir;
        pq.pop();
                
        for (int i = 0; i < dx.size(); i++)
        {
            int NewRow = Row + dy[i];
            int NewCol = Col + dx[i];
            if (CanGo(NewRow, NewCol, board))
            {
                int NewCost = Cost; 
                int NewDir = Dir;
                CalculateCost(NewCost, i, NewDir);
                
                if (NewCost <= Visited[NewRow][NewCol][NewDir])
                {
                    Visited[NewRow][NewCol][NewDir] = NewCost;
                    pq.push({NewRow, NewCol, NewCost, NewDir});
                }
            }
        }
    }
    
    return min(Visited[N - 1][N - 1][0], Visited[N - 1][N - 1][1]);
}