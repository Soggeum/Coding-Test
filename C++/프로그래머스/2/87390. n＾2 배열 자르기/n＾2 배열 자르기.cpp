#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int row, col;
    for (; left <= right; left++) {
        row = left / n + 1;
        col = left % n;
        if (col <= row - 1) {
            answer.push_back(row);
        }
        else 
        {
            answer.push_back(col + 1);
        }
    }
    
    return answer;
}