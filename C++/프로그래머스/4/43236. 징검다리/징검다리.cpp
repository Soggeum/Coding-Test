#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    
    int answer = 1000000000, Start = 1, End = distance;
    while (Start <= End)
    {
        int mid = (Start + End) / 2, LastRock = 0, RemoveCount = 0;
        for (int i = 0; i < rocks.size(); i++)
        {
            if (rocks[i] - LastRock >= mid)
            {
                LastRock = rocks[i];
            }
            else
            {
                RemoveCount++;
            }
        }
        if (distance - LastRock < mid)
        {
            RemoveCount++;
        }
        
        if (RemoveCount <= n)
        {
            answer = mid;
            Start = mid + 1;
        }
        else
        {
            End = mid - 1;
        }
        
    }
    return answer;
}