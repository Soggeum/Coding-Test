#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Throw, SingleBull;    
};

vector<int> solution(int target) {
    vector<Node> DP(target + 1, {target + 1, 0});
    vector<int> SB;
    vector<int> DT;
    for (int i = 1; i <= 20; i++)
    {
        SB.push_back(i);
        DT.push_back(i * 2);
        DT.push_back(i * 3);
    }
    SB.push_back(50);
    
    for (int dt : DT)
    {
        if (dt < DP.size())
        {
            DP[dt] = {1, 0};            
        }
    }
    for (int sb : SB)
    {
        if (sb < DP.size())
        {
            DP[sb] = {1, 1};            
        }
    }
    
    for (int i = 1; i < target; i++)
    {
        for (int sb : SB)
        {
            int NewScore = i + sb;
            if (NewScore <= target)
            {
                if (DP[NewScore].Throw > DP[i].Throw + 1)
                {
                    DP[NewScore].Throw = DP[i].Throw + 1;
                    DP[NewScore].SingleBull = DP[i].SingleBull + 1;
                }
                else if (DP[NewScore].Throw == DP[i].Throw + 1)
                {
                    DP[NewScore].SingleBull = max(DP[NewScore].SingleBull, DP[i].SingleBull + 1);
                }
            }
        }
        
        for (int dt : DT)
        {
            int NewScore = i + dt;
            if (NewScore <= target)
            {
                if (DP[NewScore].Throw > DP[i].Throw + 1)
                {
                    DP[NewScore].Throw = DP[i].Throw + 1;
                    DP[NewScore].SingleBull = DP[i].SingleBull;
                }
                else if (DP[NewScore].Throw == DP[i].Throw + 1)
                {
                    DP[NewScore].SingleBull = max(DP[NewScore].SingleBull, DP[i].SingleBull);
                }
            }
        }
    }
    
    
    return {DP[target].Throw, DP[target].SingleBull};
}