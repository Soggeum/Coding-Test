#include <string>
#include <vector>

using namespace std;

int CalculateDist(int x, int y, int r, int c)
{
    return abs(x - r) + abs(y - c);    
}

bool IsIn(int NewX, int NewY, int N, int M)
{
    if (NewX < 1 || NewX > N)
    {
        return false;
    }
    if (NewY < 1 || NewY > M)
    {
        return false;
    }
    return true;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int Dist = CalculateDist(x, y, r, c);
    if (Dist > k || (k - Dist) % 2)
    {
        return "impossible";
    }
       
    string answer;
    answer.reserve(k);
    vector<int> dx = {1, 0, 0, -1};     // d l r u
    vector<int> dy = {0, -1, 1, 0};     // d l r u
    vector<char> dir = {'d', 'l', 'r', 'u'};
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < dx.size(); j++)
        {
            int NewX = x + dx[j], NewY = y + dy[j];
            if (IsIn(NewX, NewY, n, m))
            {
                int RemainingDist = CalculateDist(NewX, NewY, r, c);
                if (RemainingDist <= k - (i + 1))
                {
                    answer.push_back(dir[j]);
                    x = NewX;
                    y = NewY;
                    break;
                }
            }
        }
    }
    
    return answer;
}