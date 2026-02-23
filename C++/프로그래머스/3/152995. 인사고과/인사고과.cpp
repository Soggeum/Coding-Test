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
    const vector<int> wanho = scores[0];
    sort(scores.begin(), scores.end(), comp);
    
    int answer = 1, PeerMax = 0;
    for (const vector<int>& s : scores)
    {
        if (s[1] < PeerMax)
        {
            if (s == wanho)
            {
                return -1;
            }
        }
        else
        {
            PeerMax = max(PeerMax, s[1]);
            if (s[0] + s[1] > wanho[0] + wanho[1])
            {
                answer++;
            }
        }
        
    }
    
    return answer;
}