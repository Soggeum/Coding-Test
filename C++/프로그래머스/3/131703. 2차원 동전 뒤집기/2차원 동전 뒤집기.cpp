#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int N = beginning.size(), M = beginning[0].size(), answer = N + M + 1;
    for (int i = 0; i < (1 << N); i++)
    {
        vector<vector<int>> Table = beginning;
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            {
                cnt++;
                for (int col = 0; col < M; col++)
                {
                    Table[j][col] ^= 1;
                }
            }
        }
        
        bool bFlag = true;
        for (int col = 0; col < M; col++)
        {
            bool bSame = false, bDiff = false;
            for (int row = 0; row < N; row++)
            {
                if (Table[row][col] ^ target[row][col])
                {
                    bDiff = true;
                }
                else
                {
                    bSame = true;
                }
            }
            if (bSame && bDiff)
            {
                bFlag = false;
                break;
            }
            else if (bDiff)
            {
                cnt++;
            }
        }
        
        if (bFlag)
        {
            answer = min(answer, cnt);
        }
    }
    
    return answer == N + M + 1 ? -1 : answer;
}