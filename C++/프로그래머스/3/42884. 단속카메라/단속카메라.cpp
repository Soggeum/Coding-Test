#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] != b[0])
    {
        return a[0] < b[0];
    }
    else
    {
        a[1] < b[1];
    }
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), comp);
       
    int answer = 0, Last = -40000;
    for (const vector<int> r : routes)
    {
        if (Last < r[0])
        {
            Last = r[1];
            answer++;
        }
        else if (Last > r[1])
        {
            Last = r[1];
        }
    }
    
    return answer;
}