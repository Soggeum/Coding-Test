#include <string>
#include <vector>

using namespace std;

struct Node
{
    long long time;
    long long time_prev;
};

int solution(vector<int> diffs, vector<int> times, long long limit) {
    vector<Node> DiffTime(100001, {0, 0});
    DiffTime[1] = {times[0], 0};
    long long TotalTime = times[0];    
    int MaxLevel = 1;
    for (int i = 1; i < diffs.size(); i++)
    {
        TotalTime += times[i];
        MaxLevel = max(MaxLevel, diffs[i]);
        
        DiffTime[diffs[i]].time += times[i];
        DiffTime[diffs[i]].time_prev += times[i - 1];
    }
    
    int MinLevel = MaxLevel - 1;
    long long PlusTime = 0;
    for (; MinLevel >= 1; MinLevel--)
    {
        PlusTime += DiffTime[MinLevel + 1].time + DiffTime[MinLevel + 1].time_prev;
        TotalTime += PlusTime;
        if (TotalTime > limit)
        {
            return MinLevel + 1;
        }
    }
    
    return 1;
}