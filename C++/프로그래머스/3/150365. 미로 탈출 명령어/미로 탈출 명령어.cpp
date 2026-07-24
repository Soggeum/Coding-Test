#include <string>
#include <vector>

using namespace std;

bool IsPossible(int n, int m, int x, int y, int r, int c, int k)
{
    if (x < 1 || x > n || y < 1 || y > m)
    {
        return false;
    }
    
    int Move = abs(x - r) + abs(y - c);
    if (Move > k)
    {
        return false;
    }
    return !((Move - k) & 1);
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    
    int Move = abs(x - r) + abs(y - c);
    if (Move > k || (Move - k) & 1)
    {
        return "impossible";
    }
    
    vector<int> dy = {0, -1, 1, 0};
    vector<int> dx = {1, 0, 0, -1};
    vector<char> dir = {'d', 'l', 'r', 'u'};
    
    while (k)
    {
        k--;
        for (int i = 0; i < dx.size(); i++)
        {
            int NewX = x + dx[i], NewY = y + dy[i];
            if (IsPossible(n, m, NewX, NewY, r, c, k))
            {
                x = NewX;
                y = NewY;
                answer.push_back(dir[i]);
                break;
            }
        }
    }
    
    return answer;
}