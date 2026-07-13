#include <string>
#include <vector>
#include <limits>

using namespace std;

const vector<int> dx = {1, -1, 0, 0};
const vector<int> dy = {0, 0, 1, -1};

vector<pair<int, int>> NextPoint(int CurrX, int CurrY, const vector<vector<bool>>& LandScape, vector<vector<bool>>& Visited)
{
    vector<pair<int, int>> Result;
    for (int i = 0; i < 2; i++)
    {
        int NextX = CurrX + dx[i];
        if (NextX < 0 || NextX > 50 || Visited[CurrY][NextX])
        {
            continue;
        }
        else if (CurrY == 0)
        {
            if (LandScape[CurrY][min(NextX, CurrX)])
                Result.push_back({NextX, CurrY});
        }
        else if (CurrY == 50)
        {
            if (LandScape[CurrY - 1][min(NextX, CurrX)])
                Result.push_back({NextX, CurrY});
        }
        else if (LandScape[CurrY][min(NextX, CurrX)] ^ LandScape[CurrY - 1][min(NextX, CurrX)])
        {
            Result.push_back({NextX, CurrY});
        }
    }
    
    for (int i = 2; i < 4; i++)
    {
        int NextY = CurrY + dy[i];
        if (NextY < 0 || NextY > 50 || Visited[NextY][CurrX])
        {
            continue;
        }
        else if (CurrX == 0)
        {
            if (LandScape[min(NextY, CurrY)][CurrX])
            Result.push_back({CurrX, NextY});
        }
        else if (CurrX == 50)
        {
            if (LandScape[min(NextY, CurrY)][CurrX - 1])
            Result.push_back({CurrX, NextY});
        }
        else if (LandScape[min(NextY, CurrY)][CurrX] ^ LandScape[min(NextY, CurrY)][CurrX - 1])
        {
            Result.push_back({CurrX, NextY});
        }
    }
    
    return Result;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<bool>> LandScape(50, vector<bool>(50));
    for (const vector<int>& rec : rectangle)
    {
        for (int i = rec[1]; i < rec[3]; i++)
        {
            for (int j = rec[0]; j < rec[2]; j++)
            {
                LandScape[i][j] = true;
            }
        }
    }
    
    vector<vector<bool>> Visited(51, vector<bool>(51));
    Visited[characterY][characterX] = true;
    vector<pair<int, int>> NextLoc = NextPoint(characterX, characterY, LandScape, Visited);
    int answer = numeric_limits<int>::max();
    for (const pair<int, int> Start : NextLoc)
    {
        int CurrX = Start.first, CurrY = Start.second, Total = 1;
        Visited[CurrY][CurrX] = true;
        while (!(CurrX == itemX && CurrY == itemY))
        {
            pair<int, int> Res = NextPoint(CurrX, CurrY, LandScape, Visited)[0];
            CurrX = Res.first;
            CurrY = Res.second;
            Visited[CurrY][CurrX] = true;
            Total++;
        }
        answer = min(answer, Total);
        Visited[itemY][itemX] = false;
    }
    
    return answer;
}