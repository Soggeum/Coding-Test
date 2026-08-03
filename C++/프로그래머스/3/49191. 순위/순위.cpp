#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> Table(n + 1, vector<int>(n + 1));
    for (const vector<int>& v : results)
    {
        Table[v[0]][v[1]] = 1;
        Table[v[1]][v[0]] = -1;
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
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1;j <= n; j++)
        {
            if (Table[i][j])
            {
                count++;
            }
        }
        if (count == n - 1)
        {
            answer++;
        }
    }
    return answer;
}