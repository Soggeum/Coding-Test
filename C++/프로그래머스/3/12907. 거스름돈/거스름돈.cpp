#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int m : money)
    {
        for (int i = m; i <= n; i++)
        {
            dp[i] += dp[i - m];
            dp[i] %= 1000000007;
        }
    }
    return dp[n];
}