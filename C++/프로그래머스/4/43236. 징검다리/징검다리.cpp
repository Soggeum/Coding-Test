#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    int answer = 0, Start = 1, End = distance;
    while (Start <= End)
    {
        int MinDist = (Start + End) / 2;
        int LastPoint = 0, Delete = 0;
        for (int r : rocks)
        {
            if (r - LastPoint >= MinDist)
            {
                LastPoint = r;
            }
            else
            {
                Delete++;                
            }
        }
        if (distance - LastPoint < MinDist)
        {
            Delete++;
        }
        
        if (Delete <= n)
        {
            answer = MinDist;
            Start = MinDist + 1;
        }
        else
        {
            End = MinDist - 1;
        }
    }
    return answer;
}