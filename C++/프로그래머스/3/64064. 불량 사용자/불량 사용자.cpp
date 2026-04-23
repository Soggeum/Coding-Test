#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool IsTarget(const string& id, const string& ban)
{
    if (id.length() != ban.length())
    {
        return false;
    }
    
    for (int i = 0; i < id.size(); i++)
    {
        if (ban[i] == '*')
        {
            continue;
        }
        
        if (id[i] != ban[i])
        {
            return false;
        }
    }
    
    return true;
}

vector<int> FindTargetIdx(const vector<string>& user_id, const string& ban)
{
    vector<int> Result;
    for (int i = 0; i < user_id.size(); i++)
    {
        if (IsTarget(user_id[i], ban))
        {
            Result.push_back(i);
        }
    }
    return Result;
}

int MakeIdx(const vector<bool>& Check)
{
    int Result = 0;
    for (int i = 0; i < Check.size(); i++)
    {
        if (Check[i])
        {
            Result += pow(2, i);
        }
    }
    return Result;
}

void FindCase(vector<bool>& Case, const vector<vector<int>>& PossibleTargets, vector<bool>& Check, int now)
{
    if (now == PossibleTargets.size())
    {
        int idx = MakeIdx(Check);
        Case[idx] = true;
        return;
    }
    
    for (int Target : PossibleTargets[now])
    {
        if (Check[Target])
        {
            continue;
        }
        
        Check[Target] = true;
        FindCase(Case, PossibleTargets, Check, now + 1);
        Check[Target] = false;        
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int N = user_id.size();
    vector<bool> Case(pow(2, N));
    
    vector<vector<int>> PossibleTargets;
    for (const string& ban : banned_id)
    {
        PossibleTargets.push_back(FindTargetIdx(user_id, ban));
    }
    
    vector<bool> Check(N);
    FindCase(Case, PossibleTargets, Check, 0);
    int answer = 0;
    for (bool b : Case)
    {
        if (b)
        {
            answer++;
        }
    }
    return answer;
}