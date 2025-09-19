#include <string>
#include <vector>

using namespace std;

long long DP(int n, vector<long long>& dp) {
    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = (DP(n - 1, dp) + DP(n - 2, dp)) % 1234567;
    return dp[n];
}

long long solution(int n) {
    vector<long long> dp(2001, -1);
    dp[1] = 1;
    dp[2] = 2;
    
    return DP(n, dp);
}