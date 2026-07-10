#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node 
{
    int CrossNum, Count;
    bool operator<(const Node& a) const
    {
        return Count < a.Count;
    }
};

int solution(vector<int> a) {
    vector<int> Table(500001);
    for(int Num : a)
    {
        Table[Num]++;
    }

    priority_queue<Node> pq;
    for (int i = 0; i < Table.size(); i++)
    {
        if (Table[i])
        {
            pq.push({i, Table[i]});
        }
    }
    
    int answer = 0;
    while(!pq.empty())
    {
        int CrossNum = pq.top().CrossNum, Count = pq.top().Count;
        pq.pop();
        
        if (Count < answer)
        {
            return answer;
        }
        
        int len = 0, LastIdx = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == CrossNum)
            {
                Count--;
                if (i - 1 != LastIdx && i != 0 && a[i - 1] != CrossNum)
                {
                    len += 2;
                    LastIdx = i;
                }
                else if (i + 1 < a.size() && a[i + 1] != a[i])
                {
                    len += 2;
                    LastIdx = i + 1;
                    i++;
                }
                if (Count == 0)
                {
                    break;
                }
            }
        }
        
        answer = max(answer, len);
    }
    
    return answer;
}