#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPillarOK(const vector<vector<bool>>& PillarTable,
                const vector<vector<bool>>& BeamTable,
                int x, int y)
{
    if (y == 0 || PillarTable[y - 1][x] || BeamTable[y][x] || (x > 0 && BeamTable[y][x - 1]))
    {
        return true;
    }
    return false;
}

bool IsBeamOK(const vector<vector<bool>>& PillarTable,
                const vector<vector<bool>>& BeamTable,
                int x, int y)
{
    if (PillarTable[y - 1][x] || PillarTable[y - 1][x + 1] || (x > 0 && BeamTable[y][x - 1] && BeamTable[y][x + 1]))
    {
        return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<bool>> PillarTable(n + 1, vector<bool>(n + 1));
    vector<vector<bool>> BeamTable(n + 1, vector<bool>(n + 1));
    for (const vector<int>& bf : build_frame)
    {
        int x = bf[0], y = bf[1], a = bf[2], b = bf[3];
        if (b == 1)
        {
            if (a == 0)
            {
                if (IsPillarOK(PillarTable, BeamTable, x, y))
                {
                    PillarTable[y][x] = true;
                }
            }
            else
            {
                if (IsBeamOK(PillarTable, BeamTable, x, y))
                {
                    BeamTable[y][x] = true;
                }
            }
        }
        else
        {
            if (a == 0)
            {
                PillarTable[y][x] = false;
                if (PillarTable[y + 1][x] && !IsPillarOK(PillarTable, BeamTable, x, y + 1))
                {
                    PillarTable[y][x] = true;
                }                
                else if (BeamTable[y + 1][x] && !IsBeamOK(PillarTable, BeamTable, x, y + 1))
                {
                    PillarTable[y][x] = true;
                }
                else if (x > 0 && BeamTable[y + 1][x - 1] && !IsBeamOK(PillarTable, BeamTable, x - 1, y + 1))
                {
                    PillarTable[y][x] = true;
                }
            }
            else
            {
                BeamTable[y][x] = false;
                if (PillarTable[y][x + 1] && !IsPillarOK(PillarTable, BeamTable, x + 1, y))
                {
                    BeamTable[y][x] = true;
                }                
                else if (PillarTable[y][x] && !IsPillarOK(PillarTable, BeamTable, x, y))
                {
                    BeamTable[y][x] = true;
                }
                else if (BeamTable[y][x + 1] && !IsBeamOK(PillarTable, BeamTable, x + 1, y))
                {
                    BeamTable[y][x] = true;
                }
                else if (x > 0 && BeamTable[y][x - 1] && !IsBeamOK(PillarTable, BeamTable, x - 1, y))
                {
                    BeamTable[y][x] = true;
                }
            }
        }
    }
    
    vector<vector<int>> answer;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (PillarTable[i][j])
            {
                answer.push_back({j, i, 0});
            }
            if (BeamTable[i][j])
            {
                answer.push_back({j, i, 1});
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}