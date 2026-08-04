#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> res;
    for (const vector<int>& ball : balls)
    {
        int a = ball[0], b = ball[1];
        int answer = 999999999;
        if (!(startX == a && startY < b))
        {
            answer = min(answer, (startX - a)*(startX - a) + (n*2 - b - startY)*(n*2 - b - startY));
        }
        if (!(startX == a && startY > b))
        {
            answer = min(answer, (startX - a)*(startX - a) + (b + startY)*(b + startY));
        }
        if (!(startY == b && startX < a))
        {
            answer = min(answer, (2*m - startX - a)*(2*m -startX - a) + (b - startY)*(b - startY));
        }
        if (!(startY == b && startX > a))
        {
            answer = min(answer, (startX + a)*(startX + a) + (b - startY)*(b - startY));
        }
        res.push_back(answer);
    }
    return res;
}