#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void DFS(const string& order, int idx, int c, vector<int> Pick, unordered_map<string, int>& um)
{
    if (Pick.size() == c)
    {
        string res;
        for (int i : Pick)
        {
            res.push_back(order[i]);
        }
        sort(res.begin(), res.end());
        um[res]++;
        return;
    }
    
    if (idx >= order.size())
    {
        return;
    }
    
    DFS(order, idx + 1, c, Pick, um);
    Pick.push_back(idx);
    DFS(order, idx + 1, c, Pick, um);
}

void Combination(const string& order, int c, unordered_map<string, int>& um)
{
    vector<int> Pick;
    DFS(order, 0, c, Pick, um);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int c : course)
    {
        unordered_map<string, int> um;
        for (const string& order : orders)
        {
            Combination(order, c, um);
        }
        int MaxCnt = 2;
        vector<string> Table;
        for (auto it = um.begin(); it !=um.end(); it++)
        {
            if (MaxCnt == it->second)
            {
                Table.push_back(it->first);
            }
            else if (MaxCnt < it->second)
            {
                MaxCnt = it->second;
                Table = {it->first};
            }
        }
        for (const string& s : Table)
        {
            answer.push_back(s);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}