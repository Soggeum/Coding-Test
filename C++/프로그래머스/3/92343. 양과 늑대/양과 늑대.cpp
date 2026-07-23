#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(int Cur, int Sheep, int Wolf, unordered_set<int> Next, int& answer, const vector<int>& info, const vector<vector<bool>>& Graphs)
{
    if (info[Cur])
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
    if (Sheep > answer)
    {
        answer = Sheep;
    }
    
    Next.erase(Cur);
    for (int j = 0; j < Graphs[Cur].size(); j++)
    {
        if (Graphs[Cur][j])
        {
            Next.insert(j);
        }
    }
    
    for (int n : Next)
    {
        DFS(n, Sheep, Wolf, Next, answer, info, Graphs);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<bool>> Graphs(info.size(), vector<bool>(info.size()));
    for (const vector<int>& edge : edges)
    {
        Graphs[edge[0]][edge[1]] = true;
    }
    
    int answer = 0;
    DFS(0, 0, 0, {0}, answer, info, Graphs);    
    
    return answer;
}