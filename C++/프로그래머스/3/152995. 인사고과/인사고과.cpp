#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] != b[0])
    {
        return a[0] > b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> scores) {
    vector<int> wh = scores[0];
    int wh_score = scores[0][0] + scores[0][1];
    sort(scores.begin(), scores.end(), comp);
    int answer = 1, MaxPeer = 0;
    for (const vector<int>& sc : scores)
    {
        if (wh == sc)
        {
            if (sc[1] < MaxPeer)
            {
                return -1;
            }
            continue;
        }
        if (sc[1] >= MaxPeer)
        {
            if (sc[0] + sc[1] > wh_score)
            {
                answer++;                
            }
            MaxPeer = sc[1];
        }
    }
    
    return answer;
}