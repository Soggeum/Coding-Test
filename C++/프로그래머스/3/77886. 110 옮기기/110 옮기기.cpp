#include <string>
#include <vector>

using namespace std;

bool IsOneOneZero(const vector<char>& St)
{
    int N = St.size();
    if (N >= 3)
    {
        char A = St[N - 3], B = St[N - 2], C = St[N - 1];
        if (A == '1' && B == '1' && C == '0')
        {
            return true;
        }
    }
    return false;
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (const string S : s)
    {
        string Result;
        Result.reserve(S.size());
        vector<char> St;
        int Count = 0;
        for (char C : S)
        {
            St.push_back(C);
            if (IsOneOneZero(St))
            {
                St.pop_back(); St.pop_back(); St.pop_back();
                Count++;
            }
        }
        
        int LastZero = -1;
        for (int i = St.size() - 1; i >= 0; i--)
        {
            if (St[i] == '0')
            {
                LastZero = i;
                break;
            }
        }
        int idx = 0;
        for (; idx <= LastZero; idx++)
        {
            Result.push_back(St[idx]);
        }
        for (int i = 0; i < Count; i++)
        {
            Result.append("110");
        }
        for (; idx < St.size(); idx++)
        {
            Result.push_back(St[idx]);
        }
        answer.push_back(Result);        
    }
    return answer;
}