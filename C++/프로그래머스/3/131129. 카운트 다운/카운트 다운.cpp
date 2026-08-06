#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Count, SB;    
};

vector<int> solution(int target) {
    vector<int> SingleBull;
    for (int i = 1; i <= 20; i++)
    {
        SingleBull.push_back(i);
    }
    SingleBull.push_back(50);
    
    vector<int> DoubleTriple;
    for (int i = 21; i <= 60; i++)
    {
        if (i % 2 == 0 && i / 2 <= 20)
        {
            DoubleTriple.push_back(i);
        }
        else if (i % 3 == 0 && i / 3 <= 20)
        {
            DoubleTriple.push_back(i);            
        }
    }
    
    vector<Node> DP(target + 1, {99999999, 0});
    DP[0] = {0, 0};
    for (int i = 0; i < target; i++)
    {
        for (int d : SingleBull)
        {
            if (i + d <= target)
            {
                if (DP[i + d].Count > DP[i].Count + 1)
                {
                    DP[i + d] = {DP[i].Count + 1, DP[i].SB + 1};
                }
                else if (DP[i + d].Count == DP[i].Count + 1)
                {
                    DP[i + d].SB = max(DP[i + d].SB, DP[i].SB + 1);
                }
            }
        }
        
        for (int d : DoubleTriple)
        {
            if (i + d <= target)
            {
                if (DP[i + d].Count > DP[i].Count + 1)
                {
                    DP[i + d] = {DP[i].Count + 1, DP[i].SB};
                }
                else if (DP[i + d].Count == DP[i].Count + 1)
                {
                    DP[i + d].SB = max(DP[i + d].SB, DP[i].SB);
                }
            }
        }
    }
    
    
    return {DP[target].Count, DP[target].SB};
}