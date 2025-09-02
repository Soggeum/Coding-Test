#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int basket[1000] = {0};
    int top = -1;

    for (int line : moves) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][line - 1]) {
                basket[++top] = board[i][line - 1];
                board[i][line - 1] = 0;
                break;
            }
        }

        while ((top >= 1) && (basket[top] == basket[top - 1])) {
            top -= 2;
            answer += 2;
        }
    }

    return answer;
}