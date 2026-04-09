#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

set<pair<int, int>> DFS(char t, vector<string>& Outer, int r, int c, vector<vector<bool>>& Visit)
{    
    set<pair<int, int>> Res;
    for (int i = 0; i < dx.size(); i++)
    {
        int nr = r + dx[i], nc = c + dy[i];
        if (0 <= nr && nr < Outer.size() && 0 <= nc && nc < Outer[0].size())
        {
            if (Visit[nr][nc] == false)
            {
                Visit[nr][nc] = true;
                if (Outer[nr][nc] == t)
                {
                    Res.insert({nr, nc});
                }
                else if (Outer[nr][nc] == '0')
                {
                    for (const pair<int, int>& s : DFS(t, Outer, nr, nc, Visit))
                    {
                        Res.insert(s);
                    }
                }
            }
        }
    }
    
    return Res;
}

set<pair<int, int>> RemoveOuter(char c, vector<string>& Outer)
{
    vector<vector<bool>> Visit(Outer.size(), vector<bool>(Outer[0].size()));
    return DFS(c, Outer, 0, 0, Visit);
}

int solution(vector<string> storage, vector<string> requests) {
    int n = storage.size(), m = storage[0].size();
    int answer = n * m;
    vector<string> Outer(n + 2, string(m + 2, '0'));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            Outer[i][j] = storage[i - 1][j - 1];
        }
    }
    
    for (const string& req : requests)
    {
        char c = req[0];
        if (req.size() == 2)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (Outer[i][j] == c)
                    {
                        answer--;
                        Outer[i][j] = '0';
                    }
                }
            } 
        }
        else
        {
            for (const pair<int, int>& rem : RemoveOuter(c, Outer))
            {
                answer--;
                Outer[rem.first][rem.second] = '0';
            }
        }
    }
    
    return answer;
}