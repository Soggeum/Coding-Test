#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

struct Node
{
    string Dest;
    bool Visited;  
};

bool comp(const Node& a, const Node& b)
{
    return a.Dest < b.Dest;
}

void DFS(vector<string>& answer, unordered_map<string, vector<Node>>& Table, const int& TicketNum, bool& flag)
{
    if (flag)
    {
        return;
    }
    if (answer.size() == TicketNum + 1)
    {
        flag = true;
        return;
    }
    
    string Curr = answer.back();
    for (Node& node : Table[Curr])
    {
        if (!(node.Visited))
        {
            node.Visited = true;
            answer.push_back(node.Dest);
            DFS(answer, Table, TicketNum, flag);
            if (flag)
            {
                return;
            }
            node.Visited = false;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<Node>> Table;
    for (const vector<string>& t : tickets)
    {
        Table[t[0]].push_back({t[1], false});
    }
    for (auto& it : Table)
    {
        sort(it.second.begin(), it.second.end(), comp);
    }
    
    vector<string> answer = {"ICN"};
    bool flag = false;
    DFS(answer, Table, tickets.size(), flag);
    return answer;
}