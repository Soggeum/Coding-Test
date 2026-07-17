#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> DP(info.size(), vector<int>(m, -1));
    if (info[0][0] < n)
    {
        DP[0][0] = info[0][0];
    }
    if (info[0][1] < m)
    {
        DP[0][info[0][1]] = 0;
    }
    
    for (int i = 1; i < info.size(); i++)
    {
        int EvidA = info[i][0], EvidB = info[i][1];
        for (int j = 0; j < m; j++)   
        {
            if (DP[i - 1][j] != -1 && DP[i - 1][j] + EvidA < n)
            {
                DP[i][j] = DP[i - 1][j] + EvidA;
            }
            if (j - EvidB >= 0 && DP[i - 1][j - EvidB] != -1)
            {
                if (DP[i][j] == -1)
                {
                    DP[i][j] = DP[i - 1][j - EvidB];
                }
                else
                {
                    DP[i][j] = min(DP[i][j], DP[i - 1][j - EvidB]);
                }                
            }
        }
    }
    
    int answer = 150;
    for (int i = 0; i < m; i++)
    {
        if (DP[info.size() - 1][i] != -1)
        {
            answer = min(answer, DP[info.size() - 1][i]);
        }
    }
    return answer == 150 ? -1 : answer;
}