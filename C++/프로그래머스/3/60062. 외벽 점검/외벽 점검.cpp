#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    sort(weak.begin(), weak.end());
    int answer = 10, m = weak.size();
    for (int i = 0; i < m; i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    do
    {
        for (int Start = 0; Start < m; Start++)
        {
            int Curr = Start, End = Start + m, cnt = 0;
            for (int d : dist)
            {
                cnt++;
                int Dest = weak[Curr] + d;
                while (Curr < End && weak[Curr] <= Dest)
                {
                    Curr++;
                }
                
                if (Curr >= End)
                {
                    answer = min(answer, cnt);
                    break;
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    
    return answer == 10 ? -1 : answer;
}