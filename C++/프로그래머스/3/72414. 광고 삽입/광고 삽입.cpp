#include <string>
#include <vector>

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
    vector<int> TimeTable(TotalTime);
    for (const string& log : logs)
    {
        string Start = log.substr(0, 8);
        string End = log.substr(9);
        TimeTable[TimeToSec(Start)]++;
        TimeTable[TimeToSec(End)]--;
    }
    
    for (int i = 1; i < TimeTable.size(); i++)
    {
        TimeTable[i] += TimeTable[i - 1];
    }
    
    int k = TimeToSec(adv_time);
    long long PlayCount = 0;
    int Time = 0;
    for (; Time < k; Time++)
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