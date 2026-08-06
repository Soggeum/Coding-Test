#include <string>
#include <vector>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int Move = abs(x - r) + abs(y - c);
    if (Move > k || (k - Move) & 1)
    {
        return "impossible";
    }
    
    vector<char> dir = {'d', 'l', 'r', 'u'};
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    
    string answer = "";
    while (k)
    {
        for (int i = 0; i < dir.size(); i++)
        {
            int NewX = x + dx[i], NewY = y + dy[i];
            if (NewX > 0 && NewX <= n && NewY > 0 && NewY <= m)
            {
                if (abs(NewX - r) + abs(NewY - c) <= k)
                {
                    answer.push_back(dir[i]);
                    x = NewX;
                    y = NewY;
                    break;
                }
            }
        }
        k--;
    }
    return answer;
}