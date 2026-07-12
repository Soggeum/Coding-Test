#include <string>
#include <vector>
#include <queue>

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
    vector<vector<Edge>> Edges(n + 1);
    for (const vector<int>& path : paths)
    {
        int i = path[0], j = path[1], w = path[2];
        Edges[i].push_back({j, w});
        Edges[j].push_back({i, w});
    }
    
    vector<bool> bGates(n + 1);
    for (int gate : gates)
    {
        bGates[gate] = true;
    }
    vector<bool> bSummits(n + 1);
    for (int summit : summits)
    {
        bSummits[summit] = true;
    }
    
    vector<int> answer = {50001, 10000001};
    vector<int> Visited(n + 1, 10000001);
    priority_queue<Node> pq;
    for (int gate : gates)
    {
        pq.push({gate, 0});
        Visited[gate] = 0;
    }
    
    while(!pq.empty())
    {
        int Curr = pq.top().Curr, Intensity = pq.top().Intensity;
        pq.pop();

        if (Intensity > Visited[Curr])
        {
            continue;
        }

        if (bSummits[Curr])
        {
            if (Intensity < answer[1])
            {
                answer = {Curr, Intensity};
            }
            if (Intensity == answer[1] && Curr < answer[0])
            {
                answer = {Curr, Intensity};
            }
            continue;
        }

        for (const Edge& edge : Edges[Curr])
        {
            int NewIntensity = max(Intensity, edge.Weight);
            if (!bGates[edge.Dest] && NewIntensity < Visited[edge.Dest])
            {
                pq.push({edge.Dest, NewIntensity});
                Visited[edge.Dest] = NewIntensity;
            }
        }
    }
    
    return answer;
}