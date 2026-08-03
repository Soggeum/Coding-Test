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
    vector<int> wanho = scores[0];
    sort(scores.begin(), scores.end(), comp);
    int MaxPeer = -1, answer = 1;
    for (const vector<int>& s : scores)
    {
        if (s == wanho)
        {
            if (s[1] < MaxPeer)
            {
                return -1;
            }
        }
        if (s[1] >= MaxPeer)
        {
            MaxPeer = s[1];
            if (s[0] + s[1] > wanho[0] + wanho[1])
            {
                answer++;
            }
        }
    }
    
    return answer;
}