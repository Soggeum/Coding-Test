#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    queue<pair<int, int>> NearLand;
    int Sum;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[0].size(); j++) {
            if (maps[i][j] != 'X') {
                Sum = 0;
                NearLand.push({i, j});
                while (!NearLand.empty()) {
                    int row = NearLand.front().first;
                    int col = NearLand.front().second;
                    NearLand.pop();
                    if (maps[row][col] == 'X')
                        continue;
                    Sum += maps[row][col] - '0';   
                    maps[row][col] = 'X';
                    
                    for (int k = 0; k < dx.size(); k++) {
                        int NewRow = row + dy[k], NewCol = col + dx[k];
                        if (NewRow < 0 || NewRow == maps.size())
                            continue;
                        if (NewCol < 0 || NewCol == maps[0].size())
                            continue;
                        
                        if (maps[NewRow][NewCol] != 'X')
                            NearLand.push({NewRow, NewCol});
                    }
                }
                
                answer.push_back(Sum);
            }
        }
    }
    
    if (answer.size() == 0)
        return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}