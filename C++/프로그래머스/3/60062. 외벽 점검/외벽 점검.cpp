#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Go(const vector<int>& Target, const vector<int>& dist)
{
    int Curr = 0, Friend = 0;
    while (Curr < Target.size() && Friend < dist.size())
    {
        int Next = Target[Curr] + dist[Friend++];
        auto it = upper_bound(Target.begin(), Target.end(), Next);
        Curr = it - Target.begin();
        if (Curr == Target.size())
        {
            return Friend;
        }
    }
    return 10;
    
}

int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(), dist.end());
    int answer = 10;
    do
    {
        for (int Start = 0; Start < weak.size(); Start++)
        {
            vector<int> Target(weak.begin() + Start, weak.end());
            for (int i = 0; i < Start; i++)
            {
                Target.push_back(n + weak[i]);
            }
            
            int Res = Go(Target, dist);
            if (Res != 10)
            {
                answer = min(answer, Res);
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    
    return answer == 10 ? -1 : answer;
}