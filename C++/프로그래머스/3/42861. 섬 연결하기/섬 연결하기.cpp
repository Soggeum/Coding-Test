#include <string>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    map<int, vector<pair<int, int>>> Edges;
    
    for (const vector<int> cost : costs)
    {
        Edges[cost[0]].push_back({cost[2], cost[1]});
        Edges[cost[1]].push_back({cost[2], cost[0]});
    }
    
    int start = 0;
    priority_queue<
        pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> Table;
    for (auto it = Edges.begin(); it != Edges.end(); it++)
    {
        if (it->second.size() != 0)
        {
            start = it->first;
            for (const pair<int, int>& Edge : it->second)
            {
                Table.push(Edge);
            }
            break;
        }
    }
    unordered_set<int> Visit;
    Visit.insert(start);
    
    int answer = 0;
    while(Visit.size() < n)
    {
        int Dist = Table.top().first;
        int Dest = Table.top().second;
        Table.pop();
        
        if (Visit.find(Dest) != Visit.end())
        {
            continue;
        }
        
        answer += Dist;
        Visit.insert(Dest);
        for (const pair<int, int>& Edge : Edges[Dest])
        {
            Table.push(Edge);
        }
    }
    
    return answer;
}