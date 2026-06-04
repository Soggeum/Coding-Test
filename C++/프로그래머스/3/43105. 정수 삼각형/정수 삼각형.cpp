#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> DP;
    DP.reserve(triangle.size());
    for(int i = 0; i < triangle.size(); i++)
    {
        vector<int> Temp(i + 1);
        DP.push_back(Temp);
    }
    DP[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            if (j == 0)
            {
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            }
            else if (j == triangle[i].size() - 1)
            {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + triangle[i][j];
            }
        }
    }
    
    return *max_element(DP.back().begin(), DP.back().end());
}