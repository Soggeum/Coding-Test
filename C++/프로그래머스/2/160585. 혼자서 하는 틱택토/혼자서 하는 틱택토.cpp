#include <string>
#include <vector>

using namespace std;

bool checkWin(const vector<string>& board, char c) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;
    }
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == c && board[1][j] == c && board[2][j] == c)
            return true;
    }
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
    return false;
}

int solution(vector<string> board) {
    int cntO = 0, cntX = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'O') cntO++;
            else if (board[i][j] == 'X') cntX++;
        }
    }

    if (cntX > cntO) return 0;
    if (cntO - cntX > 1) return 0;

    bool oWin = checkWin(board, 'O');
    bool xWin = checkWin(board, 'X');

    if (oWin && xWin) return 0;

    if (oWin && cntO != cntX + 1) return 0;
    if (xWin && cntO != cntX) return 0;

    return 1;
}