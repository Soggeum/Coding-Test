#include <string>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<vector<bool>> Table(n + 1, vector<bool>(n + 1, false));
    for (const vector<int> road : roads)
    {
        Table[road[0]][road[1]] = true;
        Table[road[1]][road[0]] = true;
    }
    
    const int INF = numeric_limits<int>::max();
    vector<int> Time(n + 1, INF);
    Time[destination] = 0;
    queue<pair<int, int>> q;
    q.push({destination, 0});
    while(!q.empty())
    {
        int start = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (dist > Time[start])
        {
            continue;
        }
        
        for (int i = 1; i <= n; i++)
        {
            if(Table[start][i] && Time[i] > dist + 1)
            {
                Time[i] = dist + 1;
                q.push({i, dist + 1});
            }
        }
    }
    
    vector<int> answer;
    for (int s : sources)
    {
        if (Time[s] == INF)
        {
            answer.push_back(-1);
        }
        else
            answer.push_back(Time[s]);
    }
    return answer;
}