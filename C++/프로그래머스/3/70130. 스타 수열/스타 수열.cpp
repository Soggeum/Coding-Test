#include <string>
#include <vector>

using namespace std;

struct Node
{
    int Last, Cnt;    
};

int solution(std::vector<int> a) {
    vector<Node> Table(a.size(), {-1, 0}); 
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i];
        if (Table[x].Last != i - 1)
        {
            Table[x].Last = i;
            Table[x].Cnt += 2;
        }
        else if (i + 1 < a.size() && x != a[i + 1])
        {
            Table[x].Last  = i + 1;
            Table[x].Cnt += 2;
        }
        else
        {
            Table[x].Last = i;
        }
    }
    
    
    int answer = 0;
    for (int i = 0; i < Table.size(); i++)
    {
        answer = max(answer, Table[i].Cnt);
    }
    return answer;
}