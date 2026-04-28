#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int TimeToMinute(const string& time)
{
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string MinuteToTime(int Minute)
{
    int Hour = Minute / 60;
    Minute -= Hour * 60;
    string Result, sHour = to_string(Hour), sMinute = to_string(Minute);
    if (sHour.length() < 2)
    {
        Result.push_back('0');
    }
    Result.append(sHour);
    Result.push_back(':');
    if (sMinute.length() < 2)
    {
        Result.push_back('0');
    }
    Result.append(sMinute);
    
    return Result;    
}

string solution(int n, int t, int m, vector<string> timetable) {
    sort(timetable.begin(), timetable.end());
    
    int BusMinute = TimeToMinute("09:00");
    string BusTime;
    int FirstWaitingIdx = 0;
    while (n > 1)
    {
        BusTime = MinuteToTime(BusMinute);
        for (int i = 0; i < m; i++)
        {
            if (FirstWaitingIdx >= timetable.size())
            {
                break;
            }
            
            if (BusTime >= timetable[FirstWaitingIdx])
            {
                FirstWaitingIdx++;
            }
            else
            {
                break;
            }
        }
        
        BusMinute += t;
        n--;
    }
    
    BusTime = MinuteToTime(BusMinute);
    for (int i = 0; i < m; i++)
    {
        if (FirstWaitingIdx >= timetable.size())
        {
            return BusTime;
        }

        if (BusTime >= timetable[FirstWaitingIdx])
        {
            FirstWaitingIdx++;
        }
        else
        {
            return BusTime;
        }
    }
    
    string answer = "";
    return MinuteToTime(TimeToMinute(timetable[FirstWaitingIdx - 1]) - 1);
}