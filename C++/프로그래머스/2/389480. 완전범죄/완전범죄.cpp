#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> DP(info.size(), vector<int>(m, n));
    if (info[0][0] < n)
    {
        DP[0][0] = info[0][0];
    }
    if (info[0][1] < m)
    {
        DP[0][info[0][1]] = 0;
    }
    
    for (int i = 0; i < info.size() - 1; i++)
    {
        int NextA = info[i + 1][0], NextB = info[i + 1][1];
        for (int j = 0; j < m; j++)
        {
            if (DP[i][j] < n)
            {
                if (DP[i][j] + NextA < n)
                {
                    DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + NextA);
                }
                if (j + NextB < m)
                {
                    DP[i + 1][j + NextB] = min(DP[i + 1][j + NextB], DP[i][j]);
                }
            }
        }
    }
        
    int answer = n;
    for (int n : DP.back())
    {
        answer = min(answer, n);
    }
    return answer == n ? -1 : answer;
}