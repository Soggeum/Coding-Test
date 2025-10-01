#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> table;
    for (const auto& temp : clothes) {
        table[temp[1]]++;
    }
    
    int N = table.size();
    vector<int> dp(N, -1);
    dp[0] = table.begin()->second;
    
    int n = 1;
    for (auto it = ++table.begin(); it != table.end(); it++, n++) {
        dp[n] = dp[n - 1] + dp[n - 1] * (it->second) + (it->second); 
    }
    
    return dp[N - 1];
}