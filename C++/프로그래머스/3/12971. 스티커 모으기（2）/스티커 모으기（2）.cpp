#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    if (sticker.size() == 1)
    {
        return sticker[0];
    }
    int N = sticker.size();
    vector<int> DP1(N), DP2(N);
    DP1[0] = sticker[0];
    DP1[1] = sticker[0];
    for (int i = 2;i < N - 1; i++)
    {
        DP1[i] = max(DP1[i - 2] + sticker[i], DP1[i - 1]);
    }
    DP1[N - 1] = DP1[N - 2];
    
    DP2[0] = 0;
    DP2[1] = sticker[1];
    for (int i = 2;i < N; i++)
    {
        DP2[i] = max(DP2[i - 2] + sticker[i], DP2[i - 1]);
    } 

    return max(DP1.back(), DP2.back());
}