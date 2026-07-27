#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int CrossNum, Count;    
    bool operator<(const Node& Other) const
    {
        return Count < Other.Count;
    }
};

int solution(std::vector<int> a) {
    vector<int> Table(a.size());
    for (int n : a)
    {
        Table[n]++;
    }
    
    priority_queue<Node> pq;
    for (int i = 0; i < Table.size(); i++)
    {
        pq.push({i, Table[i]});
    }
    
    int answer = 0;
    while(!pq.empty())
    {
        int CrossNum = pq.top().CrossNum, Count = pq.top().Count;
        pq.pop();
        
        if (Count * 2 <= answer)
        {
            continue;
        }
        
        int LastIdx = -1, Len = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == CrossNum)
            {
                Count--;
                if (i - 1 >= 0 && a[i - 1] != CrossNum && i - 1 > LastIdx)
                {
                    Len += 2;
                    LastIdx = i;
                }
                else if (i + 1 < a.size() && a[i + 1] != CrossNum)
                {
                    Len += 2;
                    LastIdx = i + 1;
                    i++;
                }
                
                if (Count == 0)
                {
                    break;
                }
            }
        }
        
        answer = max(answer, Len);
    }
    
    return answer;
}