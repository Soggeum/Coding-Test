#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> Table(n + 1, vector<int>(n + 1));
    for (const vector<int>& r : results)
    {
        Table[r[0]][r[1]] = 1;
        Table[r[1]][r[0]] = -1;
    }
    
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (Table[i][k] != 0 && Table[i][k] == Table[k][j])
                {
                    Table[i][j] = Table[i][k];
                }
            }
        }
    }
    
    int answer = 0;
    for (const vector<int>& row : Table)
    {
        int Count = 0;
        for (int num : row)
        {
            if (num)
            {
                Count++;
            }
        }
        if (Count == n - 1)
        {
            answer++;
        }
    }
    return answer;
}