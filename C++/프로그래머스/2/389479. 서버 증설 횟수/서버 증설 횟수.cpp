#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, server = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < players.size(); i++)
    {
        if(!q.empty())
        {
            int DueTime = q.front().first;
            int Count = q.front().second;
            if (DueTime == i)
            {
                server -= Count;
                q.pop();
            }
        }
        
        int NeededServer = players[i] / m;
        int Count = NeededServer - server;
        if (Count > 0)
        {
            answer += Count;
            q.push({i + k, Count});
            server = NeededServer;
        }
    }
    
    return answer;
}