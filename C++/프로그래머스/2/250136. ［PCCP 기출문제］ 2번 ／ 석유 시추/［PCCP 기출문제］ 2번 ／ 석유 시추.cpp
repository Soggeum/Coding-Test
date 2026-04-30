#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

static int GroupNum = 1;

void FindAndFill(int row, int col, const vector<vector<int>>& land, vector<vector<pair<int, int>>>& Table)
{
    int Amount = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    
    queue<pair<int, int>> q;
    queue<pair<int, int>> LaterQ;
    q.push({row, col});
    while(!q.empty())
    {
        row = q.front().first;
        col = q.front().second;
        q.pop();
        
        if (land[row][col] == 0 || Table[row][col].second)
        {
            continue;
        }
        
        LaterQ.push({row, col});
        
        Amount++;
        Table[row][col].second = Amount;
        for (int i = 0; i < dx.size(); i++)
        {
            int NextRow = row + dy[i], NextCol = col + dx[i];
            if (NextRow >= 0 && NextRow < land.size() && NextCol >= 0 && NextCol < land[0].size() && land[NextRow][NextCol] == 1 && Table[NextRow][NextCol].second == 0)
            {
                q.push({NextRow, NextCol});
            }
        }
    }
    
    while(!LaterQ.empty())
    {
        row = LaterQ.front().first;
        col = LaterQ.front().second;
        LaterQ.pop();
        
        Table[row][col].second = Amount;
        Table[row][col].first = GroupNum;
    }
    GroupNum++;
}

int solution(vector<vector<int>> land) {
    int n = land.size(), m = land[0].size();
    vector<vector<pair<int, int>>> Table(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] == 0 || Table[i][j].first != 0)
            {
                continue;
            }
            
            FindAndFill(i, j, land, Table);
        }
    }
     
    int MaxAmount = 0;
    for (int j = 0; j < m; j++)
    {
        int Amount = 0;
        set<int> Groups;
        for (int i = 0; i < n; i++)
        {
            if (land[i][j] == 1 && Groups.find(Table[i][j].first) == Groups.end())
            {
                Amount += Table[i][j].second;
                Groups.insert(Table[i][j].first);
            }
        }
        MaxAmount = max(MaxAmount, Amount);
    }
    return MaxAmount;
}