#include <string>
#include <vector>

using namespace std;

int GetSec(const string& Time)
{
    int Res = 0;
    Res += stoi(Time.substr(0, 2)) * 60 * 60;
    Res += stoi(Time.substr(3, 2)) * 60;
    Res += stoi(Time.substr(6, 2));
    return Res;
}

string GetTime(int Time)
{
    int Hour = Time / 3600;
    Time %= 3600;
    int Min = Time / 60;
    Time %= 60;
    
    string Res;
    if (Hour < 10)
    {
        Res.push_back('0');
    }
    Res.append(to_string(Hour));
    Res.push_back(':');
    if (Min < 10)
    {
        Res.push_back('0');
    }
    Res.append(to_string(Min));
    Res.push_back(':');
    if (Time < 10)
    {
        Res.push_back('0');
    }
    Res.append(to_string(Time));
    return Res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int TotalSec = GetSec(play_time);
    vector<int> Table(TotalSec);
    
    for (const string& l : logs)
    {
        int Start = GetSec(l.substr(0, 8)), End = GetSec(l.substr(9));
        Table[Start]++;
        if (End < TotalSec)
        {
            Table[End]--;
        }
    }
    for (int i = 1; i < TotalSec; i++)
    {
        Table[i] += Table[i - 1];
    }
    
    int Left = 0, Right = GetSec(adv_time);
    long long Count = 0;
    for (int i = Left; i < Right; i++)
    {
        Count += Table[i];
    }
    long long MaxCount = Count;
    string Answer = "00:00:00";
    while (Right <= TotalSec)
    {
        Count -= Table[Left++];
        if (Right == TotalSec)
        {
            break;
        }
        Count += Table[Right++];
        
        if (Count > MaxCount)
        {
            MaxCount = Count;
            Answer = GetTime(Left);
        }
    }
    
    return Answer;
}