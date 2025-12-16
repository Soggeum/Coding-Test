#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

struct Node {
    int row;
    int col;
    int cnt;
};

int solution(vector<string> board) {
    vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
    int R_row, R_col;
    
    for (int i = 0; i < board.size(); ++i) {
        for(int j = 0; j < board[0].size(); ++j) {
            if(board[i][j] == 'R') {
                R_row = i;
                R_col = j;
                break;
            }
        }
    }
    
    queue<Node> q;
    q.push( {R_row, R_col, 0});
    visit[R_row][R_col] = true;
    while(!q.empty()) {
        Node top = q.front(); q.pop();
        if (board[top.row][top.col] == 'G')
            return top.cnt;
        
        int backup = top.row;
        if (top.row != 0 && board[--top.row][top.col] != 'D') {
            while (top.row >= 0) {
                if (top.row == 0 || board[top.row - 1][top.col] == 'D') {
                    if (visit[top.row][top.col] == false) {
                        q.push({top.row, top.col, top.cnt + 1});
                        visit[top.row][top.col] = true;
                    }
                    break;
                }
                top.row--;
                
            }
        }        
        top.row = backup;
        if (top.row != board.size() - 1 && board[++top.row][top.col] != 'D') {
            while (top.row < board.size()) {
                if (top.row == board.size() - 1 || board[top.row + 1][top.col] == 'D' ) {
                    if (visit[top.row][top.col] == false) {
                        q.push({top.row, top.col, top.cnt + 1});
                        visit[top.row][top.col] = true;
                    }
                    break;
                }
                top.row++;
                
            }
        }
        top.row = backup;
        
        backup = top.col;
        if (top.col != 0 && board[top.row][--top.col] != 'D') {
            while (top.col >= 0) {
                if (top.col == 0 || board[top.row][top.col - 1] == 'D') {
                    if (visit[top.row][top.col] == false) {
                        q.push({top.row, top.col, top.cnt + 1});
                        visit[top.row][top.col] = true;
                    }
                    break;
                }
                top.col--;
                
            }
        }
        top.col = backup;
        
        
        if (top.col != board[0].size() - 1 && board[top.row][++top.col] != 'D') {
            while (top.col < board[0].size()) {
                if (top.col == board[0].size() - 1 || board[top.row][top.col + 1] == 'D') {
                    if (visit[top.row][top.col] == false) {
                        q.push({top.row, top.col, top.cnt + 1});
                        visit[top.row][top.col] = true;
                    }
                    break;
                }
                top.col++;
                
            }
        }
        top.col = backup;
    }
    
    return -1;
}