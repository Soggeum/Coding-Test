#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    vector<char> dir = {'d', 'l', 'r', 'u'};
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};

    int MoveCount = abs(x - r) + abs(y - c);
    if (MoveCount > k || (MoveCount - k) & 1)
    {
        return "impossible";
    }
    
    string answer = "";
    while(k)
    {
        for (int i = 0; i < dir.size(); i++)
        {
            int NewX = x + dx[i], NewY = y + dy[i];
            if (NewX < 1 || NewX > n || NewY < 1 || NewY > m)
            {
                continue;
            }
            if (abs(NewX - r) + abs(NewY - c) > k)
            {
                continue;
            }
            
            x = NewX;
            y = NewY;
            answer.push_back(dir[i]);
            break;
        }
        
        k--;
    }
    return answer;
}