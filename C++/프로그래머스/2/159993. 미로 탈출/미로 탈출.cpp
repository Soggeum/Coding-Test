#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int row;
    int col;
    int cnt;
};

bool IsIn(int y, int x, int n, int m) {
    if (y >= 0 && y < n && x >= 0 && x < m)
        return true;
    return false;
}

int BFS(const vector<string>& maps, const pair<int, int>& from, const pair<int, int>& to) {
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n = maps.size(), m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Node> q;
    q.push({from.first, from.second, 0});
    
    while(!q.empty()) {
        int CurRow = q.front().row;
        int CurCol = q.front().col;
        int Cnt = q.front().cnt;
        q.pop();
        if (visited[CurRow][CurCol])
            continue;
        visited[CurRow][CurCol] = true;
        
        if (CurRow == to.first && CurCol == to.second)
            return Cnt;
        
        for (int i = 0; i < dx.size(); i++) {
            if (IsIn(CurRow + dy[i], CurCol + dx[i], n, m)) {
                if (maps[CurRow + dy[i]][CurCol + dx[i]] != 'X') {
                    q.push({CurRow + dy[i], CurCol + dx[i], Cnt + 1});
                }
            }
        }
    }
    
    
    return -1;
}

int solution(vector<string> maps) {
    pair<int, int> start, lever, exit;
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S')
                start = {i, j};
            else if (maps[i][j] == 'L')
                lever = {i, j};
            else if (maps[i][j] == 'E')
                exit = {i, j};
        }
    }
    
    int StartToLever = BFS(maps, start, lever);
    if (StartToLever == -1)
        return -1;
    
    int LeverToExit = BFS(maps, lever, exit);
    if (LeverToExit == -1)
        return -1;
    
    return StartToLever + LeverToExit;
}