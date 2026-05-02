#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

void DFS(int N, int C, string& Res, int Idx, vector<string>& Result)
{
    if (Res.length() == C)
    {
        Result.push_back(Res);
        return;
    }
    if (Idx > N)
    {
        return;
    }
    
    DFS(N, C, Res, Idx + 1, Result);
    Res.push_back('0' + Idx);
    DFS(N, C, Res, Idx + 1, Result);
    Res.pop_back();
}

vector<string> MakeCombinations(int N, int C)
{
    vector<string> Result;
    string Res;
    DFS(N, C, Res, 1, Result);
    return Result;
}

bool _IsMinimal(const string& Key, const string& CandidateKey)
{
    for (char c : CandidateKey)
    {
        if (!binary_search(Key.begin(), Key.end(), c))
        {
            return true;
        }
    }
    return false;
}

bool IsMinimal(const string& Key, const vector<string>& Keys)
{
    for (const string& CandidateKey : Keys)
    {
        if (!_IsMinimal(Key, CandidateKey))
        {
           return false; 
        }
    }
    return true;
}

void MakeUnknownCandidateKeys(int N, queue<string>& UnknownCandidateKeys)
{
    for (int i = 1; i <= N; i++)
    {
        vector<string> Res = MakeCombinations(N, i);
        for (const string& R : Res)
        {
            UnknownCandidateKeys.push(R);
        }
    }
}

bool IsUnique(const string& UnknownCandidateKey, const vector<vector<string>>& relation)
{
    set<string> Tuples;
    for (int i = 0; i < relation.size(); i++)
    {
        string Tuple;
        for (char c : UnknownCandidateKey)
        {
            Tuple.append(relation[i][c - '0' - 1]);
        }
        if (Tuples.find(Tuple) != Tuples.end())
        {
            return false;
        }
        else
        {
            Tuples.insert(Tuple);
        }
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    queue<string> UnknownCandidateKeys;
    vector<string> CandidateKeys;
    MakeUnknownCandidateKeys(relation[0].size(), UnknownCandidateKeys);
    
    while (!UnknownCandidateKeys.empty())
    {
        string UnknownCandidateKey = UnknownCandidateKeys.front();
        UnknownCandidateKeys.pop();
        
        if (!IsMinimal(UnknownCandidateKey, CandidateKeys))
        {
            continue;
        }
        
        if (IsUnique(UnknownCandidateKey, relation))
        {
            CandidateKeys.push_back(UnknownCandidateKey);
        }
    }
    
    return CandidateKeys.size();
}
