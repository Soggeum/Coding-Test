#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long TotalTime = 0;
    vector<pair<int, int>> TimeTable;
    TimeTable.reserve(food_times.size());
    for (int i = 0; i < food_times.size(); i++)
    {
        TotalTime += food_times[i];
        TimeTable.push_back({food_times[i], i});
    }
    if (TotalTime <= k)
    {
        return -1;
    }
    sort(TimeTable.begin(), TimeTable.end());
    
    int N = TimeTable.size(), idx;
    long long OneCycleTime, PrevTime = 0;
    for (int i = 0; i < TimeTable.size(); i++)
    {
        OneCycleTime = (TimeTable[i].first - PrevTime) * N;
        if (OneCycleTime <= k)
        {
            PrevTime = TimeTable[i].first;
            k -= OneCycleTime;
            N--;
        }
        else
        {
            idx = i;
            break;
        }
    }
    k %= N;
    
    sort(TimeTable.begin() + idx, TimeTable.end(), comp);
    return TimeTable[idx + k % N].second + 1;
}