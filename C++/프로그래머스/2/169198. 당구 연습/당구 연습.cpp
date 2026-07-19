#include <string>
#include <vector>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for (const vector<int> ball : balls)
    {
        int X = ball[0], Y = ball[1];
        int Result = 2000000000;
        if (!(startX == X && startY > Y))
        {
            Result = min(Result, (startX - X) * (startX - X) + (Y + startY) * (Y + startY));
        }
        if (!(startX == X && startY < Y))
        {
            Result = min(Result, (startX - X) * (startX - X) + (n - Y + n - startY) * (n - Y + n - startY));
        }
        if (!(startY == Y && startX > X))
        {
            Result = min(Result, (startX + X) * (startX + X) + (Y - startY) * (Y - startY));
        }
        if (!(startY == Y && startX < X))
        {
            Result = min(Result, (m - startX + m - X) * (m - startX + m - X) + (Y - startY) * (Y - startY));
        }
        answer.push_back(Result);
    }
    
    return answer;
}
