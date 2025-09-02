#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int player_x = 0, player_y = 0;
    int width{ board[0] / 2 }, height { board[1] / 2 };

    for (const auto& dir : keyinput) {
        if (dir == "up") {
            player_y = min(player_y + 1, height);
        }
        else if (dir == "down") {
            player_y = max(player_y - 1, -height);
        }
        else if (dir == "right") {
            player_x = min(player_x + 1, width);
        }
        else  {
            player_x = max(player_x - 1, -width);
        }
    }

    return { player_x, player_y };
}