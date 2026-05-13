#include <string>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

struct Node
{
    int Idx, Dist;  
    
    bool operator<(const Node& b) const
    {
        return Dist > b.Dist;
    }
};

void MST(int s, vector<int>& v, const vector<vector<Node>>& Edges)
{
    priority_queue<Node> q;
    q.push({s, 0});
    while(!q.empty())
    {
        int Idx = q.top().Idx, Dist = q.top().Dist;
        q.pop();
        if (v[Idx] <= Dist)
        {
            continue;
        }
        v[Idx] = Dist;
        
        for (const Node& NextNode : Edges[Idx])
        {
            if (Dist + NextNode.Dist <= v[NextNode.Idx])
            {
                q.push({NextNode.Idx, Dist + NextNode.Dist});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<Node>> Edges(n + 1);
    for (const vector<int>& fare : fares)
    {
        Edges[fare[0]].push_back({fare[1], fare[2]});
        Edges[fare[1]].push_back({fare[0], fare[2]});
    }
    
    int InitValue = numeric_limits<int>::max();
    vector<int> DistS(n + 1, InitValue);
    vector<int> DistA(n + 1, InitValue);
    vector<int> DistB(n + 1, InitValue);
    
    MST(s, DistS, Edges);
    MST(a, DistA, Edges);
    MST(b, DistB, Edges);
    
    int answer = numeric_limits<int>::max();
    for (int k = 1; k <= n; k++)
    {
        if (DistS[k] == InitValue || DistA[k] == InitValue || DistB[k] == InitValue)
        {
            continue;
        }
        int temp = DistS[k] + DistA[k] + DistB[k];
        answer = min(answer, temp);
    }
    
    return answer;
}