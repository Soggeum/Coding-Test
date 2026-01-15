#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#include <iostream>

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer(balls.size());
    int TarX, TarY, Dist, MinDist;
    for (int i = 0; i < balls.size(); i++)
    {
        TarX = balls[i][0];
        TarY = balls[i][1];
        MinDist = 99999999;
        
        if (!(startX == TarX && startY < TarY)) 
        {
            Dist = pow(TarX - startX, 2) + pow(2 * n - startY - TarY, 2);
            MinDist = min(MinDist, Dist);
        }
        if (!(startX == TarX && startY > TarY)) 
        {
            Dist = pow(TarX - startX, 2) + pow(startY + TarY, 2);
            MinDist = min(MinDist, Dist);
        }
        if (!(startY == TarY && startX < TarX)) 
        {
            Dist = pow(TarY - startY, 2) + pow(2 * m - startX - TarX, 2);
            MinDist = min(MinDist, Dist);
        }
        if (!(startY == TarY && startX > TarX)) 
        {
            Dist = pow(TarY - startY, 2) + pow(startX + TarX, 2);
            MinDist = min(MinDist, Dist);
        }
        answer[i] = MinDist;
    }
    
    return answer;
}