#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(vector<int>& visited, const vector<vector<int>>& computers, int cur)
{    
    visited[cur] = 1;
    for (int i = 0; i < computers.size(); i++)
    {
        if (computers[cur][i] == 1 && visited[i] == 0)
        {
            DFS(visited, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<int> visited(n, 0);
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(visited, computers, i);
            answer++;
        }
    }
    
    return answer;
}