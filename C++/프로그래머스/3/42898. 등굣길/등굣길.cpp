#include <string>
#include <vector>

using namespace std;

int DP(int m, int n, vector<vector<int>>& Table)
{
    if (Table[n][m] != 0)
    {
        return Table[n][m] > 0 ? Table[n][m] : 0;
    }
    else
    {
        if (m == 0)
        {
            Table[n][m] = DP(m, n - 1, Table);
        }
        else if (n == 0)
        {
            Table[n][m] = DP(m - 1, n, Table);
        }
        else
        {
            Table[n][m] = (DP(m - 1, n, Table) + DP(m, n - 1, Table)) % 1000000007;
        }
        return Table[n][m];
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> Table(n, vector<int>(m));
    Table[1][0] = 1;
    Table[0][1] = 1;
    for (const vector<int>& puddle : puddles)
    {
        Table[puddle[1] - 1][puddle[0] - 1] = -1;
    }
    
    return DP(m - 1, n - 1, Table);
}