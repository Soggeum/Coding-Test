#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int cur, int& MaxSheep, int& Sheep, int& Wolf, vector<int> NextNodes, const vector<int>& info, const vector<vector<int>>& Tree)
{
    info[cur] == 0 ? Sheep++ : Wolf++;
    if (Sheep <= Wolf)
    { 
        info[cur] == 0 ? Sheep-- : Wolf--;
        return;
    }
    
    MaxSheep = max(MaxSheep, Sheep);
    NextNodes.erase(find(NextNodes.begin(), NextNodes.end(), cur));
    for (int node : Tree[cur])
    {
        NextNodes.push_back(node);
    }
    
    for (int Node : NextNodes)
    {
        DFS(Node, MaxSheep, Sheep, Wolf, NextNodes, info, Tree);
    }
    
    info[cur] == 0 ? Sheep-- : Wolf--;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> Tree(info.size());
    for (const vector<int> edge : edges)
    {
        Tree[edge[0]].push_back(edge[1]);
    }
    
    int MaxSheep = 0, Sheep = 0, Wolf = 0;
    vector<int> NextNodes = {0};
    DFS(0, MaxSheep, Sheep, Wolf, NextNodes, info, Tree);
    
    return MaxSheep;
}