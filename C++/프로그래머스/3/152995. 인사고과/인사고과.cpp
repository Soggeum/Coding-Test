#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

int solution(vector<vector<int>> scores) {
    vector<int> wanho = scores[0];
    sort(scores.begin(), scores.end(), comp);
    int answer = 1, Max = 0, wscore = wanho[0] + wanho[1];
    for (const vector<int>& s : scores)
    {
        if (s == wanho)
        {
            if (wanho[1] < Max)
            {
                return -1;
            }
        }
        else
        {
            if (s[1] >= Max)
            {
                Max = s[1];
                if (s[0] + s[1] > wscore)
                {
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}