#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

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

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<Edge>> Graphs(n + 1);
    for (const vector<int>& p : paths)
    {
        Graphs[p[0]].push_back({p[1], p[2]});
        Graphs[p[1]].push_back({p[0], p[2]});
    }
    
    unordered_set<int> s;
    for (int summit : summits)
    {
        s.insert(summit);
    }
    
    priority_queue<Node> pq;
    vector<bool> Visited(n + 1);
    for (int g : gates)
    {
        pq.push({g, 0});
    }
    vector<int> answer = {50001, 10000001};
    while (!pq.empty())
    {
        int Curr = pq.top().Curr, Intensity = pq.top().Intensity;
        pq.pop();
        
        if (Visited[Curr])
        {
            continue;
        }
        Visited[Curr] = true;
        
        if (s.find(Curr) != s.end())
        {
            if (Intensity == answer[1])
            {
                answer[0] = min(answer[0], Curr);
            }
            else if (Intensity < answer[1])
            {
                answer = {Curr, Intensity};
            }
            continue;
        }
        
        for (const Edge& e : Graphs[Curr])
        {
            if (!Visited[e.Dest])
            {
                pq.push({e.Dest, max(Intensity, e.Weight)});
            }
        }
    }
    
    return answer;
}