#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Throw, SingleBull;    
    
    bool operator<(const Node& other) const
    {
        if (Throw == other.Throw)
        {
            return SingleBull < other.SingleBull;
        }
        return Throw > other.Throw;
    }
};

vector<int> solution(int target) {
    vector<int> SB;
    for (int i = 1; i <= 20; i++)
    {
        SB.push_back(i);
    }
    SB.push_back(50);
    
    vector<int> DT;
    for (int i = 0; i < 20; i++)
    {
        DT.push_back(SB[i] * 2);
        DT.push_back(SB[i] * 3);
    }
    
    vector<Node> DP(target + 1, {100000, 100000});
    for (int dt : DT)
    {
        if (dt <= target)
        {
            DP[dt] = {1, 0};
        }
    }
    for (int sb : SB)
    {
        if (sb <= target)
        {
            DP[sb] = {1, 1};
        }
    }
    
    for (int i = 1; i < target; i++)
    {
        for (int sb : SB)
        {
            if (i + sb <= target)
            {
                Node NewNode = {DP[i].Throw + 1, DP[i].SingleBull + 1};
                DP[i + sb] = max(DP[i + sb], NewNode);
            }            
        }
        for (int dt : DT)
        {
            if (i + dt <= target)
            {
                Node NewNode = {DP[i].Throw + 1, DP[i].SingleBull};
                DP[i + dt] = max(DP[i + dt], NewNode);
            }            
        }
    }
    
    return {DP[target].Throw, DP[target].SingleBull};
}