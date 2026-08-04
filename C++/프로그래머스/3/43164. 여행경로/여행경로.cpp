#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node
{
    string Dest;
    bool bUsed;
    
    bool operator<(const Node& Other) const
    {
        return Dest < Other.Dest;
    }
};

void DFS(vector<string>& answer, unordered_map<string, vector<Node>>& um, int& TicketNum)
{
    if (answer.size() == TicketNum + 1)
    {
        return;
    }
    
    string Curr = answer.back();
    for (Node& n : um[Curr])
    {
        if (!n.bUsed)
        {
            answer.push_back(n.Dest);
            n.bUsed = true;
            DFS(answer, um, TicketNum);
            if (answer.size() == TicketNum + 1)
            {
                return;
            }
            n.bUsed = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<Node>> um;
    for (const vector<string>& t : tickets)
    {
        um[t[0]].push_back({t[1], false});
    }
    for (auto& it : um)
    {
        sort(it.second.begin(), it.second.end());
    }
    
    vector<string> answer={"ICN"};
    int n = tickets.size();
    DFS(answer, um, n);
    return answer;
}