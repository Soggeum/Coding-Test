#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> stones, int k) {
    int Left = 0, Right = k;
    multiset<int> ms;
    for (int i = Left; i < Right; i++)
    {
        ms.insert(stones[i]);
    }
    
    int answer = 200000000;
    while (Right <= stones.size())
    {
        answer = min(answer, *ms.rbegin());
        auto it = ms.find(stones[Left++]);
        ms.erase(it);
        if (Right == stones.size())
        {
            break;
        }
        ms.insert(stones[Right++]);
    }
    return answer;
}