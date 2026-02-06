#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node
{
    int CostTime;
    int RequestTime;
    int Idx;
    
    bool operator()(const Node& a, const Node& b)
    {
        if (a.CostTime != b.CostTime) return a.CostTime > b.CostTime;
        if (a.RequestTime != b.RequestTime) return a.RequestTime > b.RequestTime;
        return a.Idx > b.Idx;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    int idx = 1, time = jobs[0][0], answer = 0;
    priority_queue<Node, vector<Node>, Node> q;
    q.push({jobs[0][1], jobs[0][0], 0});
    while(idx < jobs.size() || !q.empty())
    {
        if (!q.empty())
        {
            time += q.top().CostTime;
            answer += time - q.top().RequestTime;
            q.pop();
        }
        
        for (; idx < jobs.size() && jobs[idx][0] <= time; idx++)
        {
            q.push({jobs[idx][1], jobs[idx][0], idx});
        }
        
        if (q.empty())
        {
            if (idx >= jobs.size())
            {
                break;
            }
            time = jobs[idx][0];
        }
    } 

    return answer / jobs.size();
}