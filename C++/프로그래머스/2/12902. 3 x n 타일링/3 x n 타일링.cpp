#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if (n & 1)
    {
        return 0;
    }
    vector<int> DP(n + 1);
    DP[0] = 1;
    DP[2] = 3;
    for (int i = 4; i <= n; i += 2)
    {
        DP[i] = (4ll * DP[i - 2] - DP[i - 4] + 1000000007) % 1000000007;
    }
    
    return DP[n];
}