#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> DP(n + 1);
    DP[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            DP[i] += DP[j] * DP[i - j - 1];
        }
    }
    return DP.back();
}