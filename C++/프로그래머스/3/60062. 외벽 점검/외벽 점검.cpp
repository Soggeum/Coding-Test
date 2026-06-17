#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 9, WeakNum = weak.size();
    for (int i = 0; i < WeakNum; i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    do 
    {
        for (int Start = 0; Start < WeakNum; Start++)
        {
            int Count = 0;
            int CurWeak = Start, LastWeak = Start + WeakNum - 1;
            for (int d : dist)
            {
                Count++;
                int Dest = weak[CurWeak] + d;
                while (CurWeak <= LastWeak && Dest >= weak[CurWeak])
                {
                    CurWeak++;
                }
                if (CurWeak > LastWeak)
                {
                    answer = min(answer, Count);
                    break;
                }
            }
        }        
    } while (next_permutation(dist.begin(), dist.end()));
    
    return answer == 9 ? -1 : answer;
}