#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> DP(info.size(), vector<int>(m, 123456789));
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
        int A = info[i][0], B = info[i][1];
        for (int j = 0; j < m; j++)
        {
            int NewA = DP[i - 1][j] + A;
            if (NewA < n)
            {
                DP[i][j] = min(DP[i][j], NewA);
            }
            if (j - B >= 0)
            {
                DP[i][j] = min(DP[i][j], DP[i - 1][j - B]);
            }
        }
    }
    
    int answer = 123456789;
    for (int i = 0; i < m; i++)
    {
        answer = min(answer, DP[info.size() - 1][i]);
    }
    
    return answer == 123456789 ? -1 : answer;
}