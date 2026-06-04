#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> Works;
    for (int work : works)
    {
        Works.push(work);
    }
    
    int Front;
    for (int i = 0; i < n; i++)
    {
        Front = Works.top();
        if (Front == 0)
        {
            return 0;
        }
        Works.pop();
        Works.push(--Front);
    }
    
    long long answer = 0, Top;
    while(!Works.empty())
    {
        Top = Works.top();  Works.pop();
        answer += Top * Top;
    }
    return answer;
}