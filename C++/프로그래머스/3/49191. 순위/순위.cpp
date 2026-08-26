#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> Table(n + 1, vector<int>(n + 1));
    for (const vector<int>& r : results)
    {
        int A = r[0], B = r[1];
        Table[A][B] = 1;
        Table[B][A] = -1;
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
    for (const vector<int> r : Table)
    {
        int cnt = 0;
        for (int v : r)
        {
            if (v)
            {
                cnt++;
            }
        }
        if (cnt == n - 1)
        {
            answer++;
        }
    }
    return answer;
}