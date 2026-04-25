#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> stones, int k) { 
    multiset<int> Targets;
    int low = 0, high = k;
    for (int i = 0; i < k; i++)
    {
        Targets.insert(stones[i]);
    }
    int answer = *Targets.rbegin();
    
    for (; high < stones.size(); low++, high++)
    {
        Targets.erase(Targets.find(stones[low]));
        Targets.insert(stones[high]);
        answer = min(answer, *Targets.rbegin());
    }
    
    return answer;
}