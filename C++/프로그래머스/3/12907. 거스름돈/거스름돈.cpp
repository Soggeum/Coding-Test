#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> DP(n + 1);
    DP[0] = 1;
    for (int m : money)
    {
        for (int i = m; i <= n; i++)
        {
            DP[i] += DP[i - m];
        }
    }
    return DP[n];
}