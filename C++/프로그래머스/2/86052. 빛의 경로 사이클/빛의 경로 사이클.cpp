#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    char Dir;
    
    // Up, Right, Down, Left
    vector<bool> bIsCyclePath = vector<bool>(4, false);
};

int FindCycle(vector<vector<Node>>& Table, int i, int j, int k)
{
    // Up, Right, Down, Left
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    
    int result = 0;
    
    while (Table[i][j].bIsCyclePath[k] == false)
    {
        Table[i][j].bIsCyclePath[k] = true;
        result++;
        i += dy[k];
        i = (i == -1) ? Table.size() - 1 : (i == Table.size() ? 0 : i);
        j += dx[k];
        j = (j == -1) ? Table[0].size() - 1 : (j == Table[0].size() ? 0 : j);
    
        switch (Table[i][j].Dir)
        {
            case 'S' :
                break;
            case 'L' :
                k = (k + 3) % 4;
                break;
            case 'R' : 
                k = (k + 1) % 4;
                break;
            default : 
                break;      
        }
    }
    
    return result;
}

vector<int> solution(vector<string> grid) {
    vector<vector<Node>> Table(grid.size(), vector<Node>(grid[0].size()));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            Table[i][j].Dir = grid[i][j];
        }
    }
    
    vector<int> answer;
    for (int i = 0; i < Table.size(); i++)
    {
        for (int j = 0; j < Table[0].size();j ++)
        {
            for (int k = 0; k < Table[i][j].bIsCyclePath.size(); k++)
            {
                if (Table[i][j].bIsCyclePath[k] == false)
                {
                    answer.push_back(FindCycle(Table, i, j, k));                    
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}