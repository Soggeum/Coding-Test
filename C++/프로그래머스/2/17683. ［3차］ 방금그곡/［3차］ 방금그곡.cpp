#include <string>
#include <vector>
#include <sstream>

using namespace std;

int GetDuration(const string & Start, const string& End)
{
    int StartMinute = stoi(Start.substr(0, 2)) * 60 + stoi(Start.substr(3));
    int EndMinute = stoi(End.substr(0, 2)) * 60 + stoi(End.substr(3));
    
    return EndMinute - StartMinute;
}

string solution(string m, vector<string> musicinfos) {
    string M_;
    for (char c : m)
    {
        if (c == '#')
        {
            *M_.rbegin() = tolower(*M_.rbegin());
        }
        else
        {
            M_.push_back(c);
        }
    }
    m = M_;
    
    string answer;
    int answerTime = -1;
    for (string& musicinfo : musicinfos)
    {    
        stringstream ss(musicinfo);
        string Start, End, Title, Data;
        getline(ss, Start, ',');
        getline(ss, End, ',');
        getline(ss, Title, ',');
        getline(ss, Data, ',');
        string Data_;
        for (char c : Data)
        {
            if (c == '#')
            {
                *Data_.rbegin() = tolower(*Data_.rbegin());
            }
            else
            {
                Data_.push_back(c);
            }
        }
        Data = Data_;
        
        int Duration = GetDuration(Start, End);
        if (m.length() > Duration)
        {
            continue;
        }
               
        string TestData;
        for (int i = 0; i < Duration; i++)
        {
            TestData.push_back(Data[i % Data.length()]);
        }
        if (TestData.find(m) != string::npos)
        {
            if (answerTime < Duration)
            {
                answer = Title;
                answerTime = Duration;
            }
        }
    }
    
    if (answer.empty())
    {
        return "(None)";
    }
    return answer;
}