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

string GetTime(int Sec)
{
    int Hour = Sec / (60 * 60);
    Sec -= Hour * 60 * 60;
    int Min = Sec / 60;
    Sec -= Min * 60;
    
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
    if (Sec < 10)
    {
        Res.push_back('0');
    }
    Res.append(to_string(Sec));
    
    return Res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    vector<int> Table(GetSec(play_time));
    for (const string& log : logs)
    {
        string Start = log.substr(0, 8), End = log.substr(9);
        int start_sec = GetSec(Start);
        int end_sec = GetSec(End);

        Table[start_sec] += 1;
        if (end_sec < Table.size())
        {
            Table[end_sec] -= 1; 
        }
    }
    
    for (int i = 1; i < Table.size(); i++)
    {
        Table[i] += Table[i - 1];
    }
    
    int Start = 0, End = GetSec(adv_time);
    long long Sum = 0, MaxSum = 0;
    for (int i = Start; i < End; i++)
    {
        Sum += Table[i];
    }
    
    string answer = "00:00:00";
    while (End <= Table.size())
    {
        if (Sum > MaxSum)
        {
            answer = GetTime(Start);
            MaxSum = Sum;
        }
        
        Sum -= Table[Start++];
        if (End == Table.size())
        {
            break;
        }
        Sum += Table[End++];
    }
    
    return answer;
}