#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Edge엔 도착지와 가중치
// Node엔 도착지와 intensity
// pq엔 첨에 gate만 넣고, 다익스트라 실행
// visit은 intensity로 처리

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
    for (const vector<int>& path : paths)
    {
        Graphs[path[0]].push_back({path[1], path[2]});
        Graphs[path[1]].push_back({path[0], path[2]});
    }
    
    priority_queue<Node> pq;
    vector<int> Dist(n + 1, 10000001);
    for (int g : gates)
    {
        pq.push({g, 0});
    }
    
    unordered_set<int> us;
    for (int s : summits)
    {
        us.insert(s);
    }
    
    vector<int> answer = {n, 10000001};
    while (!pq.empty())
    {
        int Curr = pq.top().Curr, Intensity = pq.top().Intensity;
        pq.pop();
        
        if (Dist[Curr] <= Intensity)
        {
            continue;
        }
        Dist[Curr] = Intensity;
        
        auto it = us.find(Curr);
        if (it != us.end())
        {
            if (answer[1] > Intensity)
            {
                answer = {Curr, Intensity};
                continue;
            }
            else if (answer[1] == Intensity)
            {
                answer[0] = min(Curr, answer[0]);
                continue;
            }
            continue;
        }
        
        for (const Edge& e : Graphs[Curr])
        {
            int Dest = e.Dest, NewI = max(Intensity, e.Weight);
            if (Dist[Dest] > NewI)
            {
                pq.push({Dest, NewI});
            }
        }
    }
    
    return answer;
}