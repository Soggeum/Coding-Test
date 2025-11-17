#include <string>
#include <vector>

using namespace std;

int Rotate(vector<vector<int>>& v, const vector<int>& query) {
    int x1 = query[0] - 1, y1 = query[1] - 1, x2 = query[2] - 1, y2 = query[3] - 1;
    int Pre = v[x1 + 1][y1], row = x1, col = y1;
    int result = v.size() * v[0].size();
    for (; col < y2; col++) {
        int now = v[row][col];
        result = min(result, now);
        v[row][col] = Pre;
        Pre = now;
    }
    for(; row < x2; row++) {
        int now = v[row][col];
        result = min(result, now);
        v[row][col] = Pre;
        Pre = now;
    }
    for(; col > y1; col--) {
        int now = v[row][col];
        result = min(result, now);
        v[row][col] = Pre;
        Pre = now;
    }
    for(; row > x1; row--) {
        int now = v[row][col];
        result = min(result, now);
        v[row][col] = Pre;
        Pre = now;
    }
    
    
    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> v(rows, vector<int>(columns));
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            v[i][j] = i * columns + j + 1;
        }
    }
    
    vector<int> answer;
    for (const auto& query : queries) {
        answer.push_back(Rotate(v, query));
    }
    
    return answer;
}