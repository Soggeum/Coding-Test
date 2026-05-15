#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int N = money.size();
    if (N == 3)
    {
        return *max_element(money.begin(), money.end());
    }
    
    vector<int> DP(N);
    DP[0] = money[0];
    DP[1] = money[0];    
    for (int i = 2; i < N - 1; i++)
    {
        DP[i] = max(DP[i - 1], DP[i - 2] + money[i]);
    }
    
    int answer = DP[N - 2];
    DP[1] = money[1];
    DP[2] = max(money[1], money[2]);
    for (int i = 3; i < N; i++)
    {
        DP[i] = max(DP[i - 1], DP[i - 2] + money[i]);
    }
    return max(answer, DP.back());
}