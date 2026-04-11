#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> Table;
    for (int w : works)
    {
        Table.push(w);
    }
    
    while (n)
    {
        int Front = Table.top();
        if (Front == 0)
        {
            return 0;
        }
        Table.pop();
        Table.push(Front - 1);
        n--;
    }
    
    while(!Table.empty())
    {
        answer += Table.top() * Table.top();
        Table.pop();
    }
    return answer;
}