#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(int& answer, int Curr, int Sheep, int Wolf, const vector<int>& info, const vector<vector<int>>& Trees, unordered_set<int> Next)
{
    Next.erase(Curr);
    
    if(info[Curr])
    {
        Wolf++;
    }
    else
    {
        Sheep++;
    }
    if (Wolf >= Sheep)
    {
        return;
    }
    
    answer = max(answer, Sheep);
    
    for (int n : Trees[Curr])
    {
        Next.insert(n);
    }
    
    for (int n : Next)
    {
        DFS(answer, n, Sheep, Wolf, info, Trees, Next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    vector<vector<int>> Trees(n);
    for (const vector<int>& e : edges)
    {
        Trees[e[0]].push_back(e[1]);
    }
    
    int answer = 0;
    DFS(answer, 0, 0, 0, info, Trees, {});
    return answer;
}