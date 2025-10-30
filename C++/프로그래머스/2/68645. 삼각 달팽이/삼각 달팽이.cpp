#include <string>
#include <vector>

using namespace std;

void Draw(int n, int num, int row, int col, vector<vector<int>>& snail) {
    if (n < 1)
        return;
    
    if (n == 1) {
        snail[row][col] = num;
        return;
    }
    
    for (int i = 0; i < n - 1; i++) {
        snail[row][col] = num;
        num++;
        row++;
    }
    for (int i = 0; i < n - 1; i++) {
        snail[row][col] = num;
        num++;
        col++;
    }
    for (int i = 0; i < n - 1; i++) {
        snail[row][col] = num;
        num++;
        row--;
        col--;
    }
    
    Draw(n - 3, num, row + 2, col + 1, snail);
}

vector<int> solution(int n) {
    vector<vector<int>> snail(n);
    for (int i = 0; i < n; i++) {
        snail[i] = vector<int>(i + 1, 0);
    }
    
    Draw(n, 1, 0, 0, snail);
    
    vector<int> answer;
    for (vector<int> row : snail) {
        for (int num : row) {
            answer.push_back(num);
        }
    }
    return answer;
}