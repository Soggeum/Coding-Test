#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int TimeToSec(const string& Time)
{
    int result = 0;
    result += stoi(Time.substr(0, 2)) * 60 * 60;
    result += stoi(Time.substr(3, 2)) * 60;
    result += stoi(Time.substr(6, 2));
    
    return result;
}

string SecToTime(int Sec)
{
    string result;
    int Hour = Sec / (60 * 60);
    Sec %= 60 * 60;
    int Minute = Sec / 60;
    Sec %= 60;
    if (Hour < 10)
    {
        result.push_back('0');
    }    
    result.append(to_string(Hour));
    result.push_back(':');
    if (Minute < 10)
    {
        result.push_back('0');
    }
    result.append(to_string(Minute));
    result.push_back(':');
    if (Sec < 10)
    {
        result.push_back('0');
    }
    result.append(to_string(Sec));
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int TotalTime = TimeToSec("99:59:59");    
    sort(logs.begin(), logs.end());
    priority_queue<int, vector<int>, greater<int>> q;
    vector<int> TimeTable(TotalTime);
    int count = 0, Time = 0, idx = 0;
    for (; Time < TotalTime; Time++)
    {
        while (idx < logs.size() && Time == TimeToSec(logs[idx].substr(0, 8)))
        {
            count++;
            q.push(TimeToSec(logs[idx].substr(9)));
            idx++;
        }
        while (!q.empty() && q.top() == Time)
        {
            count--;
            q.pop();
        }
        
        TimeTable[Time] = count;
    }
    
    int k = TimeToSec(adv_time);
    long long PlayCount = 0;
    for (Time = 0; Time < k; Time++)
    {
        PlayCount += TimeTable[Time];
    }
    
    long long MaxCount = PlayCount, InitTime = 0;
    for (; Time < TotalTime; Time++)
    {
        PlayCount -= TimeTable[Time - k];
        PlayCount += TimeTable[Time];
        if (PlayCount > MaxCount)
        {
            MaxCount = PlayCount;
            InitTime = Time - k + 1;
        }
    }
        
    return SecToTime(InitTime);
}