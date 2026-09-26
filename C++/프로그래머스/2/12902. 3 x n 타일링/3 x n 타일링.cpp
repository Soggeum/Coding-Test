#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n) {
    vector<int> DP(n + 1);
    DP[0] = 1;
    int Pre = 0;
    for (int i = 2; i <= n; i += 2)
    {
        DP[i] = (DP[i - 2] * 3ll + Pre * 2ll) % MOD;
        Pre = (Pre + DP[i - 2]) % MOD;
    }
    return DP.back();
}