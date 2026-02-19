#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> a) {
    set<int> table;
    for (int i = 1; i < a.size(); i++)
    {
        table.insert(a[i]);
    }
    
    int answer = 2, MinLeft = a[0], MinRight;
    for (int i = 1; i < a.size() - 1; i++)
    {
        table.erase(a[i]);
        MinRight = *table.begin();
        if (MinRight < a[i] && MinLeft < a[i])
        {
            continue;
        }
        
        answer++;
        MinLeft = min(MinLeft, a[i]);
    }
    
    return answer;
}