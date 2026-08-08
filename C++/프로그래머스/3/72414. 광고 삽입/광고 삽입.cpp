#include <string>
#include <vector>

using namespace std;

int GetSec(const string& Time)
{
    string H = Time.substr(0, 2);
    string M = Time.substr(3, 2);
    string S = Time.substr(6, 2);
    return stoi(H) * 3600 + stoi(M) * 60 + stoi(S);
}

string GetTime(int Time)
{
    int S = Time % 60;
    Time /= 60;
    int M = Time % 60;
    Time /= 60;
    int H = Time;
    string res;
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
    int N = GetSec(play_time);
    vector<int> Table(N);
    for (const string& l : logs)
    {
        int Start = GetSec(l.substr(0, 8));
        int End = GetSec(l.substr(9));
        Table[Start] += 1;
        if (End < N)
        {
            Table[End] -= 1;
        }
    }
    for (int i = 1;i < N; i++)
    {
        Table[i] += Table[i - 1];
    }
    
    long long Cnt = 0;
    int Start = 0, End = GetSec(adv_time);
    for (int i = Start; i < End; i++)
    {
        Cnt += Table[i];
    }
    long long Max = Cnt;
    int answer = 0;
    while (End <= N)
    {
        Cnt -= Table[Start++];
        if (End == N)
        {
            break;
        }
        Cnt += Table[End++];
        if (Cnt > Max)
        {
            Max = Cnt;
            answer = Start;
        }
    }
    
    return GetTime(answer);
}