#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int N = beginning.size(), M = beginning[0].size();
    int answer = 2100000000;
    for (int i = 0; i < (1 << (N + M)); i++)
    {
        vector<vector<int>> Table = beginning;
        int Count = 0;
        for (int j = 0; j < N + M; j++)
        {
            if (i & (1 << j))
            {
                Count++;
                if (j < M)
                {
                    for (int row = 0; row < N; row++)
                    {
                        Table[row][j] = !Table[row][j];
                    }
                }
                else
                {
                    for (int col = 0; col < M; col++)
                    {
                        Table[j - M][col] = !Table[j - M][col];
                    }
                }
            }
        }
        
        bool flag = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0;j < M; j++)
            {
                if (Table[i][j] != target[i][j])
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            answer = min(answer, Count);
        }
    }
        

    return answer == 2100000000 ? -1 : answer;
}