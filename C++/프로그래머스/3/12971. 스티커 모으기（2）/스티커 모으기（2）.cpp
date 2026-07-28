#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    if (sticker.size() < 4)
    {
        int answer = 0;
        for (int n : sticker)
        {
            answer = max(answer, n);
        }
        return answer;
    }
    vector<int> DP1(sticker.size()), DP2(sticker.size());
    DP1[0] = sticker[0];
    DP1[1] = sticker[0];
    DP2[0] = 0;
    DP2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++)
    {
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + sticker[i]);
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + sticker[i]);
    }
    DP1[sticker.size() - 1] = DP1[sticker.size() - 2];
    
    return max(DP1.back(), DP2.back());
}