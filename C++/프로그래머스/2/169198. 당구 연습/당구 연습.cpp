#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (const vector<int>& ball : balls)
    {
        int Dist = 999999999, x = ball[0], y = ball[1];
        if (!(startY == y && startX < x))
        {
            Dist = min(Dist, (y - startY) * (y - startY) + (2 * m - x - startX) * (2 * m - x - startX));
        }
        if (!(startY == y && startX > x))
        {
            Dist = min(Dist, (y - startY) * (y - startY) + (x + startX) * (x + startX));
        }
        if (!(startX==x && startY < y))
        {
            Dist = min(Dist, (startX - x) * (startX - x) + (2 * n - startY - y) * (2 * n - startY - y));
        }
        if (!(startX==x && startY > y))
        {
            Dist = min(Dist, (startX - x) * (startX - x) + (startY + y) * (startY + y));
        } 
        answer.push_back(Dist);
    }
    return answer;
}