#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

struct Edge
{
    int Dest, Weight;
};

struct Node
{
    int Curr, Intensity;
    bool operator<(const Node& Other) const
    {
        return Intensity > Other.Intensity;
    }
};

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    unordered_set<int> s;
    for (int summit : summits)
    {
        s.insert(summit);
    }
    
    vector<vector<Edge>> Graphs(n + 1);
    for (const vector<int>& path : paths)
    {
        int i = path[0], j = path[1], w = path[2];
        Graphs[i].push_back({j, w});
        Graphs[j].push_back({i, w});
    }
    
    vector<int> answer = {n, 90000000};
    vector<int> Visited(n + 1, 90000000);
    priority_queue<Node> pq;
    for (int gate : gates)
    {
        pq.push({gate, 0});
        Visited[gate] = 0;
    }
    while (!pq.empty())
    {
        int Curr = pq.top().Curr, Intensity = pq.top().Intensity;
        pq.pop();
        
        if (Intensity > Visited[Curr])
        {
            continue;
        }
        Visited[Curr] = Intensity;
        
        if (Intensity > answer[1])
        {
            continue;
        }
        
        if (s.find(Curr) != s.end())
        {
            if (answer[1] == Intensity)
            {
                answer[0] = min(answer[0], Curr);
            }
            else if (answer[1] > Intensity)
            {
                answer = {Curr, Intensity};
            }
            continue;
        }
        
        for (const Edge& e : Graphs[Curr])
        {
            int NewIntensity = max(Intensity, e.Weight);
            if (NewIntensity < Visited[e.Dest])
            {
                pq.push({e.Dest, NewIntensity});
            }
        }
    }
    
    return answer;
}