#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int _FindAnswer(const vector<int>& Weak, const vector<int>& dist, vector<bool>& Used, int PointIdx)
{
    if (PointIdx == Weak.size())
    {
        int res = 0;
        for (bool b : Used)
        {
            if (b)
            {
                res++;
            }
        }
        return res;
    }
    
    int Res = 999;
    for (int i = 0; i < dist.size(); i++)
    {
        if (!Used[i])
        {
            Used[i] = true;
            int StartPoint = Weak[PointIdx];
            int EndPoint = StartPoint + dist[i];
            int NewPointIdx = upper_bound(Weak.begin(), Weak.end(), EndPoint) - Weak.begin();
            Res = min(Res, _FindAnswer(Weak, dist, Used, NewPointIdx));
            Used[i] = false;
        }
    }
    return Res;
}

int FindAnswer(const vector<int>& Weak, const vector<int>& dist)
{
    vector<bool> Used(dist.size());
    int PointIdx = 0;
    return _FindAnswer(Weak, dist, Used, PointIdx);
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 999;
    for (int i = 0; i < weak.size(); i++)
    {
        vector<int> NewWeak(weak.begin() + i, weak.end());
        for (int j = 0; j < i; j++)
        {
            NewWeak.push_back(n + weak[j]);
        }
        answer = min(answer, FindAnswer(NewWeak, dist));
    }
    
    return answer == 999 ? -1 : answer;
}