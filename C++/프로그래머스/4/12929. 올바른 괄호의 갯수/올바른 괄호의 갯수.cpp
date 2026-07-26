#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> DP(n + 1);
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            DP[i] += DP[j] * DP[i - 1 - j];
        }
    }
    return DP[n];
}