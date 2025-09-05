#include <string>
#include <vector>

using namespace std;

void Move(const vector<string>& park, vector<int>& coord, char op, int n) {
    if (op == 'N') {
        if (coord[0] >= n) {
            for (int i = coord[0] - 1; i >= coord[0] - n; i--) {
                if (park[i][coord[1]] == 'X')
                    return;
            }
            coord[0] -= n;
            return;
        }
    }
    else if (op == 'S') {
        if (coord[0] + n < park.size()) {
            for (int i = coord[0] + 1; i <= coord[0] + n; i++) {
                if (park[i][coord[1]] == 'X')
                    return;
            }
            coord[0] += n;
            return;
        }
    }
    else if (op == 'W') {
        if (coord[1] >= n) {
            for (int i = coord[1] - 1; i >= coord[1] - n; i--) {
                if (park[coord[0]][i] == 'X')
                    return;
            }
            coord[1] -= n;
            return;
        }
    }
    else {
        if (coord[1] + n < park[0].size()) {
            for (int i = coord[1] + 1; i <= coord[1] + n; i++) {
                if (park[coord[0]][i] == 'X')
                    return;
            }
            coord[1] += n;
            return;
        }
    }

}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> coord;
    for (int i = 0; i < park.size(); i++) {
        if (park[i].find('S') != park[i].npos) {
            coord = { i, static_cast<int>(park[i].find('S')) };
            break;
        }
    }

    for (const auto& route : routes) {
        Move(park, coord, route[0], route[2] - '0');
    }

    return { coord[0], coord[1]};
}