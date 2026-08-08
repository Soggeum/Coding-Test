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
    for (int i = 0; i <= n; i += 2)
    {
        if (i + 2 <= n)
        {
            DP[i + 2] = (DP[i + 2] + 1ll * DP[i] * 3) % 1000000007;
        }
        for (int j = 4; i + j <= n; j += 2)
        {
            DP[i + j] = (DP[i + j] + 1ll * DP[i] * 2) % 1000000007;
        }
    }
    
    return DP[n];
}