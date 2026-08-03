#include <string>
#include <vector>

using namespace std;

void DFS(int Curr, vector<bool>& CanGo, const vector<vector<int>>& Graphs, const vector<int>& info, int& MaxSheep, int Sheep, int Wolf)
{
    info[Curr] ? Wolf++ : Sheep++;
    if (Wolf >= Sheep)
    {
        return;
    }
    MaxSheep = max(MaxSheep, Sheep);
    
    for (int Dest : Graphs[Curr])
    {
        CanGo[Dest] = true;
    }
    
    for (int i = 0; i < CanGo.size(); i++)
    {
        if (CanGo[i])
        {
            CanGo[i] = false;
            DFS(i, CanGo, Graphs, info, MaxSheep, Sheep, Wolf);
            CanGo[i] = true;
        }
    }
    
    for (int Dest : Graphs[Curr])
    {
        CanGo[Dest] = false;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<bool> CanGo(info.size());
    vector<vector<int>> Graphs(info.size());
    for (const vector<int>& e : edges)
    {
        Graphs[e[0]].push_back(e[1]);
    }
    
    int MaxSheep = 0;
    DFS(0, CanGo, Graphs, info, MaxSheep, 0, 0);
    return MaxSheep;
}