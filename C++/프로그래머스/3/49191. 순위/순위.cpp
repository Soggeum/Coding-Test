#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> Table(n + 1, vector<int>(n + 1));
    for (const vector<int> res : results)
    {
        Table[res[0]][res[1]] = 1;
        Table[res[1]][res[0]] = -1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Table[i][k] && Table[i][k] == Table[k][j])
                {
                    Table[i][j] = Table[i][k];
                    Table[j][i] = -Table[i][k];
                }
            }
        }
    }
        
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int res = 0;
        for (int j = 1; j <= n; j++)
        {
            if (Table[i][j])
            {
                res++;
            }
        }
        if (res == n - 1)
        {
            answer++;
        }
    }

    return answer;
}