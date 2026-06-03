#include <string>
#include <vector>

using namespace std;

void MakeComb(int idx, string Result, vector<string>& Combs, int k, int Pipe)
{
    if (idx > k)
    {
        Combs.push_back(Result);
        return;
    }
    
    for (int NextPipe = 1; NextPipe < 4; NextPipe++)
    {
        if (NextPipe == Pipe)
        {
            continue;
        }
        Result.push_back(NextPipe + '0');
        MakeComb(idx + 1, Result, Combs, k, NextPipe);
        Result.pop_back();
    }
}

void DFS(char Pipe, const vector<vector<pair<int, int>>>& Edges, vector<bool>& Infected, int Curr, int& Count, vector<bool>& Visited)
{
    if (Visited[Curr])
    {
        return;
    }
    Visited[Curr] = true;
    
    int CurPipe = Pipe - '0';
    
    for (const pair<int, int>& Elem : Edges[Curr])
    {
        int Next = Elem.first, PipeType = Elem.second;
        
        if (PipeType == CurPipe)
        {
            if (Infected[Curr] && !Infected[Next])
            {                
                Infected[Next] = true;
                Count++;
            }
        }
        DFS(Pipe, Edges, Infected, Next, Count, Visited);
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<string> Combs;
    MakeComb(1, "", Combs, k, 0);
    
    vector<vector<pair<int, int>>> Edges(n + 1);
    for (const vector<int>& edge : edges)
    {
        int x = edge[0], y = edge[1], type = edge[2];
        Edges[x].push_back({y, type});
        Edges[y].push_back({x, type});
    }
    
    int MaxNum = 0, Count;
    for (const string& Pipes : Combs)
    {
        vector<bool> Infected(n + 1);
        Infected[infection] = true;
        Count = 1;
        for (const char& Pipe : Pipes)
        {            
            vector<bool> Visited(n + 1);
            DFS(Pipe, Edges, Infected, infection, Count, Visited);
        }
        MaxNum = max(MaxNum, Count);
    }
    
    return MaxNum;
}