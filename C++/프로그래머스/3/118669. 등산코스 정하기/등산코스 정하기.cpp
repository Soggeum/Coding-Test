#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Edge
{
    int Dest, Intensity;    
};

struct Node
{
    int Curr, Intensity;    
    bool operator<(const Node& Other) const
    {
        if (Intensity == Other.Intensity)
        {
            return Curr > Other.Curr;
        }
        return Intensity > Other.Intensity;
    }
};

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<Edge>> Graphs(n + 1);
    for (const vector<int> p : paths)
    {
        Graphs[p[0]].push_back({p[1], p[2]});
        Graphs[p[1]].push_back({p[0], p[2]});
    }
    
    vector<int> Visited(n + 1, 123456789);
    priority_queue<Node> pq;
    for (int g : gates)
    {
        Visited[g] = 0;
        pq.push({g, 0});
    }
    
    unordered_set<int> summit;
    for (int s : summits)
    {
        summit.insert(s);
    }
    unordered_set<int> gate;
    for (int g : gates)
    {
        gate.insert(g);
    }
    
    vector<int> answer = {1, 123456789};
    while (!pq.empty())
    {
        int Curr = pq.top().Curr, Intensity = pq.top().Intensity;
        pq.pop();
        
        if (Intensity > answer[1])
        {
            continue;
        }
        
        if (summit.find(Curr) != summit.end())
        {
            if (Intensity < answer[1])
            {
                answer = {Curr, Intensity};
            }
            else
            {
                answer[0] = min(answer[0], Curr);
            }
            continue;
        }
        
        for (const Edge& e : Graphs[Curr])
        {
            if (gate.find(e.Dest) == gate.end())
            {
                int NewIntensity = max(Intensity, e.Intensity);
                if (Visited[e.Dest] > NewIntensity)
                {
                    pq.push({e.Dest, NewIntensity});
                    Visited[e.Dest] = NewIntensity;
                }
            }
        }
    }
    
    return answer;
}