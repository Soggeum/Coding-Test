#include <string>
#include <vector>

using namespace std;

int GetTime(const string& Time)
{
    int res = 0;
    string Hour = Time.substr(0, 2), Min = Time.substr(3, 2), Sec = Time.substr(6);
    return res += stoi(Hour) * 60 *60 + stoi(Min) * 60 + stoi(Sec);
}

string ToStr(int Time)
{
    string res;
    int S = Time % 60;
    Time /= 60;
    int M = Time % 60;
    Time /= 60;
    int H = Time;
    
    if (H < 10)
    {
        res.push_back('0');
    }
    res.append(to_string(H));
    res.push_back(':');
    if (M < 10)
    {
        res.push_back('0');
    }
    res.append(to_string(M));
    res.push_back(':');
    if (S < 10)
    {
        res.push_back('0');
    }
    res.append(to_string(S));
    
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int PlayTime = GetTime(play_time);
    vector<int> Table(PlayTime + 1);
    for (const string& log : logs)
    {
        int StartTime = GetTime(log.substr(0, 8)), EndTime = GetTime(log.substr(9, 8));
        Table[StartTime] += 1;
        Table[EndTime] -= 1;
    }
    for (int i = 1; i < Table.size(); i++)
    {
        Table[i] += Table[i - 1];
    }
    
    int Start = 0, End = GetTime(adv_time);
    long long count = 0, Max = 0;
    string answer;
    for (int i = Start; i < End; i++)
    {
        count += Table[i];
    }
    while (End <= PlayTime)
    {
        if (count > Max)
        {
            answer = ToStr(Start);
            Max = count;
        }
        count -= Table[Start++];
        if (End == PlayTime)
        {
            break;
        }
        count += Table[End++];
    }
       
    return answer;
}