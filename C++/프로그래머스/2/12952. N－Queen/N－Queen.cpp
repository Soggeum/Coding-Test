#include <string>
#include <vector>

using namespace std;

void DFS(vector<int>& table, int& answer, vector<int>& cols, int row);

void PushNext(vector<int>& table, int& answer, vector<int>& cols, int row, int queen) {
    for (int j = 0; j < row; ++j) {
        if (row - j == abs(table[j] - queen)) {
            return;
        }
    }
    
    table[row] = queen;
    DFS(table, answer, cols, row + 1);
    table[row] = -1;
}

void DFS(vector<int>& table, int& answer, vector<int>& cols, int row) {
    if (row == table.size()) {
        ++answer;
        return;
    }
    
    for (int i = 0; i < cols.size(); i++) {
        if (cols[i] == 1)
            continue;
        
        cols[i] = 1;
        PushNext(table, answer, cols, row, i);
        cols[i] = 0;
    }
}

int solution(int n) {
    vector<int> table(n, -1);
    vector<int> cols(n, 0);
    int answer = 0;
    for (int i = 0; i < n ; i++) {
        table[0] = i;
        cols[i] = 1;
        DFS(table, answer, cols, 1);
        cols[i] = 0;
    }
    
    return answer;
}