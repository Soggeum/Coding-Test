#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int N = beginning.size(), M = beginning[0].size(), answer = 30;
    for (int i = 0; i < (1 << (N + M)); i++)
    {
        int Cnt = 0, Temp = i;
        while (Temp)
        {
            Cnt++;
            Temp = Temp & (Temp - 1);
        }
        if (Cnt >= answer)
        {
            continue;
        }
        
        vector<vector<int>> Table = beginning;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                for (int col = 0; col < M; col++)
                {
                    Table[j][col] ^= 1;
                }
            }
        }
        for (int j = N; j < N + M; j++)
        {
            if (i & (1 << j))
            {
                for (int row = 0; row < N; row++)
                {
                    Table[row][j - N] ^= 1;
                }
            }
        }
        
        bool bFlag = true;
        for (int i = 0; i < N; i++)
        {
            if (!bFlag)
            {
                break;
            }
            for (int j = 0; j < M; j++)
            {
                if (Table[i][j] != target[i][j])
                {
                    bFlag = false;
                    break;
                }
            }
        }
        
        if (bFlag)
        {
            answer = Cnt;
        }
    }
    
    return answer == 30 ? -1 : answer;
}