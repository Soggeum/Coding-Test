#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    vector<int> dp(4, 0);

    vector<int> preDP;
    for (int row = 0; row < land.size(); row++) {
        preDP = dp;
        dp[0] = max(max(preDP[1], preDP[2]), preDP[3]) + land[row][0];
        dp[1] = max(max(preDP[0], preDP[2]), preDP[3]) + land[row][1];
        dp[2] = max(max(preDP[1], preDP[0]), preDP[3]) + land[row][2];
        dp[3] = max(max(preDP[1], preDP[2]), preDP[0]) + land[row][3];
    }

    return *max_element(dp.begin(), dp.end());
}