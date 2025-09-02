#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux {60}, luy{60}, rdx{0}, rdy{0};
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                lux = (lux > j) ? j: lux;
                rdx = (rdx < j + 1) ? j + 1: rdx;
                luy = (luy > i) ? i : luy;
                rdy = (rdy < i + 1) ? i + 1: rdy;
            }
        }
    }
    return vector<int> {luy, lux, rdy, rdx};
}