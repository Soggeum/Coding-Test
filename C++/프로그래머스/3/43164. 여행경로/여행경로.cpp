#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node
{
    string Dest;
    bool bUsed;    
    bool operator<(const Node& Other)
    {
        return Dest < Other.Dest;
    }
};

void DFS(unordered_map<string, vector<Node>>& um, vector<string>& answer, int UseCount, int TotalTickets, bool& bReturnFlag)
{
    if (bReturnFlag)
    {
        return;
    }
    if (UseCount == TotalTickets)
    {
        bReturnFlag = true;
        return;
    }
    
    for (Node& Next : um[answer.back()])
    {
        if (!Next.bUsed)
        {
            Next.bUsed = true;
            answer.push_back(Next.Dest);
            DFS(um, answer, UseCount + 1, TotalTickets, bReturnFlag);
            if (bReturnFlag)
            {
                return;
            }
            answer.pop_back();
            Next.bUsed = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<Node>> um;
    for (const vector<string>& ticket : tickets)
    {
        um[ticket[0]].push_back({ticket[1], false});
    }
    for (auto& it : um)
    {
        sort(it.second.begin(), it.second.end());
    }
        
    vector<string> answer = {"ICN"};
    bool bReturnFlag = false;
    DFS(um, answer, 0, tickets.size(), bReturnFlag);
    return answer;
}