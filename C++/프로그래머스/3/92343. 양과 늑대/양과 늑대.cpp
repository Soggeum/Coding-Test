#include <string>
#include <vector>

using namespace std;

void DFS(int Curr, vector<bool>& CanGo, const vector<int>& info, const vector<vector<int>>& Tree, int Sheep, int Wolf, int& MaxSheep)
{
    if (info[Curr])
    {
        Wolf++;
    }
    else
    {
        Sheep++;
    }
    if (Sheep <= Wolf)
    {
        return;
    }
    
    if (Sheep > MaxSheep)
    {
        MaxSheep = Sheep;
    }
    
    for (int Next : Tree[Curr])
    {
        CanGo[Next] = true;
    }
    for (int i = 0; i < CanGo.size(); i++)
    {
        if (CanGo[i])
        {
            CanGo[i] = false;
            DFS(i, CanGo, info, Tree, Sheep, Wolf, MaxSheep);
            CanGo[i] = true;
        }
    }
    for (int Next : Tree[Curr])
    {
        CanGo[Next] = false;
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> Tree(info.size());
    for (const vector<int>& e : edges)
    {
        Tree[e[0]].push_back(e[1]);
    }
    
    int MaxSheep = 0;
    vector<bool> CanGo(info.size(), false);
    DFS(0, CanGo, info, Tree, 0, 0, MaxSheep);
    
    return MaxSheep;
}