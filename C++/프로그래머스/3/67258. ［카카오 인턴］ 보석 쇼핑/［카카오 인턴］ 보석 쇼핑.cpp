#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void ShortenCurrentGems(queue<pair<string, int>>& CurrentGems, map<string, int>& GemsCount)
{
    while (GemsCount[CurrentGems.front().first] > 1)
    {
        GemsCount[CurrentGems.front().first]--;
        CurrentGems.pop();
    }
}


vector<int> solution(vector<string> gems) {   
    vector<int> ShortGems = {1, static_cast<int>(gems.size())};
    queue<pair<string, int>> CurrentGems;
    map<string, int> GemsCount;
    
    for (int i = 0; i < gems.size(); i++)
    {
        CurrentGems.push({gems[i], i + 1});
        GemsCount[gems[i]]++;
        
        if (GemsCount[gems[i]] == 1)
        {
            ShortGems[0] = CurrentGems.front().second;
            ShortGems[1] = CurrentGems.back().second;
        }
        else
        {
            ShortenCurrentGems(CurrentGems, GemsCount);
        
            if (ShortGems[1] - ShortGems[0] + 1 > CurrentGems.size())
            {
                ShortGems[0] = CurrentGems.front().second;
                ShortGems[1] = CurrentGems.back().second;
            }
        }
    }
    
    return ShortGems;
}