#include <string>
#include <vector>

using namespace std;

bool _CanUnlock(int i, int j, const vector<vector<int>>& Key, const vector<vector<int>>& Lock, int ZeroCount)
{
    int M = Key.size();
    int FillCount = 0;
    for (int r = 0; r < M; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (Lock[i + r][j + c] == 1 && Key[r][c] == 1)
            {
                return false;
            }
            if (Lock[i + r][j + c] == 0 && Key[r][c] == 0)
            {
                return false;
            }
            if (Lock[i + r][j + c] == 0 && Key[r][c] == 1)
            {
                FillCount++;
            }
        }
    }
    if (ZeroCount == FillCount)
    {
        return true;
    }
    return false;
}

bool CanUnlock(const vector<vector<int>>& Key, const vector<vector<int>>& Lock, int ZeroCount)
{
    int M = Key.size();
    int Width = Lock.size();
    for (int i = 0; i < Width - (M - 1); i++)
    {
        for (int j = 0;j < Width - (M - 1); j++)
        {
            if (_CanUnlock(i, j, Key, Lock, ZeroCount))
            {
                return true;
            }
        }
    }    
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<vector<int>>> keys(4, vector<vector<int>>(M, vector<int>(M)));
    for (int i = 0; i < M ; i++)
    {
        for (int j = 0; j < M; j++)
        {
            keys[0][i][j] = key[i][j];
        }
    }
    
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < M ; j++)
        {
            for (int k = 0; k < M; k++)
            {
                keys[i][M - 1 - k][j] = keys[i - 1][j][k];
            }
        }
    }
    
    int Width = N + (M - 1) * 2;
    int ZeroCount = 0;
    vector<vector<int>> Lock(Width, vector<int>(Width, -1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Lock[M - 1 + i][M - 1 + j] = lock[i][j];
            if (lock[i][j] == 0)
            {
                ZeroCount++;
            }
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (CanUnlock(keys[i], Lock, ZeroCount))
        {
            return true;
        }
    }
    
    return false;
}

