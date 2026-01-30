#include <string>
#include <vector>
#include <queue>
#include <map>

#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> Graph(n);
    for (const vector<int>& e : edge)
    {
        int start = e[0] - 1;
        int end = e[1] - 1;
        Graph[start].push_back(end);
        Graph[end].push_back(start);
    }
    
    vector<bool> visited(n, false);
    visited[0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    map<int, int> m;
    while(!q.empty())
    {
        int Dist = q.front().first;
        int Start = q.front().second;
        q.pop();
        
        for (const int& End : Graph[Start])
        {
            if (visited[End])
            {
                continue;
            }
            else
            {
                q.push({Dist + 1, End});
                visited[End] = true;
                m[Dist + 1]++;
            }
        }
    }
    return m.rbegin()->second;
}