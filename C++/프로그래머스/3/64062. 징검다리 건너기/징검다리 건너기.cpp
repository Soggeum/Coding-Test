#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) {
    multiset<int> ms;
    int Start = 0, End = k, answer = 200000001;
    for (int i = Start; i < End; i++)
    {
        ms.insert(stones[i]);
    }
    
    while(End <= stones.size())
    {
        answer = min(answer, *ms.rbegin());
        auto it = ms.find(stones[Start++]);        
        ms.erase(it);
        if (End == stones.size())
        {
            break;
        }
        ms.insert(stones[End++]);
    }
    
    return answer;
}