#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {    
    vector<vector<int>> Table(n + 1, vector<int>(n + 1));
    for(const vector<int>& result : results)
    {
        Table[result[0]][result[1]] = 1;
        Table[result[1]][result[0]] = -1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Table[i][k] == 1 && Table[k][j] == 1)
                {
                    Table[i][j] = 1;
                    Table[j][i] = -1;
                }
                else if (Table[i][k] == -1 && Table[k][j] == -1)
                {
                    Table[i][j] = -1;
                    Table[j][i] = 1;
                }
            }
        }
    }
    
    int answer = 0, WinLose;
    for (int i = 1; i <= n; i++)
    {
        WinLose = 0;
        for (int j = 1; j <= n; j++)
        {
            if (Table[i][j])
            {
                WinLose++;
            }
        }
        if (WinLose == n - 1)
        {
            answer++;
        }
    }
    return answer;
}